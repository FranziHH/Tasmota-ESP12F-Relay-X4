# PalettePattern animation effect for Berry Animation Framework
#
# This animation applies colors from a color provider to specific patterns or regions.
# It allows for more complex visual effects by combining palette colors with patterns.
#
# This version supports both RichPaletteAnimation and ColorProvider instances as color sources,
# allowing for more flexible usage of color providers.

#@ solidify:PalettePatternAnimation,weak
class PalettePatternAnimation : animation.animation
  var value_buffer     # Buffer to store values for each pixel
  
  # Static definitions of parameters with constraints
  static var PARAMS = {
    # Palette pattern-specific parameters
    "color_source": {"default": nil, "type": "instance"},
    "pattern_func": {"default": nil, "type": "function"}
  }
  
  # Initialize a new PalettePattern animation
  #
  # @param engine: AnimationEngine - Required animation engine reference
  def init(engine)
    # Call parent constructor with engine
    super(self).init(engine)
    
    # Initialize non-parameter instance variables only
    self.value_buffer = []
    
    # Initialize value buffer with default frame width
    self._initialize_value_buffer()
  end
  
  # Initialize the value buffer based on current strip length
  def _initialize_value_buffer()
    var strip_length = self.engine.get_strip_length()
    self.value_buffer.resize(strip_length)
    
    # Initialize with zeros
    var i = 0
    while i < strip_length
      self.value_buffer[i] = 0
      i += 1
    end
  end
  
  # Update the value buffer based on the current time
  #
  # @param time_ms: int - Current time in milliseconds
  def _update_value_buffer(time_ms)
    var pattern_func = self.pattern_func
    if pattern_func == nil
      return
    end
    
    var strip_length = self.engine.get_strip_length()
    
    # Resize buffer if strip length changed
    if size(self.value_buffer) != strip_length
      self.value_buffer.resize(strip_length)
    end
    
    # Calculate values for each pixel
    var i = 0
    while i < strip_length
      self.value_buffer[i] = pattern_func(i, time_ms, self)
      i += 1
    end
  end
  
  # Update animation state based on current time
  #
  # @param time_ms: int - Current time in milliseconds
  # @return bool - True if animation is still running, false if completed
  def update(time_ms)
    # Call parent update method first
    if !super(self).update(time_ms)
      return false
    end
    
    # Calculate elapsed time since animation started
    var elapsed = time_ms - self.start_time
    
    # Update the value buffer
    self._update_value_buffer(elapsed)
    
    return true
  end
  
  # Render the pattern to the provided frame buffer
  #
  # @param frame: FrameBuffer - The frame buffer to render to
  # @param time_ms: int - Optional current time in milliseconds (defaults to engine time)
  # @return bool - True if frame was modified, false otherwise
  def render(frame, time_ms)
    if !self.is_running || frame == nil
      return false
    end
    
    # Use provided time or default to engine time
    if time_ms == nil
      time_ms = self.engine.time_ms
    end
    
    # Get current parameter values (cached for performance)
    var color_source = self.color_source
    if color_source == nil
      return false
    end
    
    # Calculate elapsed time since animation started
    var elapsed = time_ms - self.start_time
    
    # Apply colors from the color source to each pixel based on its value
    var strip_length = self.engine.get_strip_length()
    var i = 0
    while i < strip_length && i < frame.width
      var value = self.value_buffer[i]
      var color
      
      # Check if color_source is a ColorProvider or an animation with get_color_for_value method
      if color_source.get_color_for_value != nil
        # It's a ColorProvider or compatible object
        color = color_source.get_color_for_value(value, elapsed)
      else
        # Fallback to direct color access (for backward compatibility)
        color = color_source.current_color
      end
      
      frame.set_pixel_color(i, color)
      i += 1
    end
    
    return true
  end
  
  # Handle parameter changes
  def on_param_changed(name, value)
    if name == "pattern_func" || name == "color_source"
      # Reinitialize value buffer when pattern or color source changes
      self._initialize_value_buffer()
    end
  end
  

  
  # String representation of the animation
  def tostring()
    var strip_length = self.engine.get_strip_length()
    return f"PalettePatternAnimation(strip_length={strip_length}, priority={self.priority}, running={self.is_running})"
  end
end

# Wave pattern animation - creates sine wave patterns
#@ solidify:PaletteWaveAnimation,weak
class PaletteWaveAnimation : PalettePatternAnimation
  # Static definitions of parameters with constraints
  static var PARAMS = {
    # Wave-specific parameters only
    "wave_period": {"min": 1, "default": 5000},
    "wave_length": {"min": 1, "default": 10}
  }
  
  # Initialize a new wave pattern animation
  #
  # @param engine: AnimationEngine - Required animation engine reference
  def init(engine)
    # Call parent constructor
    super(self).init(engine)
    
    # Set default name
    self.name = "palette_wave"
  end
  
  # Override _update_value_buffer to generate wave pattern directly
  def _update_value_buffer(time_ms)
    # Cache parameter values for performance
    var wave_period = self.wave_period
    var wave_length = self.wave_length
    var strip_length = self.engine.get_strip_length()
    
    # Resize buffer if strip length changed
    if size(self.value_buffer) != strip_length
      self.value_buffer.resize(strip_length)
    end
    
    # Calculate the wave position using scale_uint for better precision
    var position = tasmota.scale_uint(time_ms % wave_period, 0, wave_period, 0, 1000) / 1000.0
    var offset = int(position * wave_length)
    
    # Calculate values for each pixel
    var i = 0
    while i < strip_length
      # Calculate the wave value (0-100) using scale_uint
      var pos_in_wave = (i + offset) % wave_length
      var angle = tasmota.scale_uint(pos_in_wave, 0, wave_length, 0, 32767)  # 0 to 2π in fixed-point
      var sine_value = tasmota.sine_int(angle)  # -4096 to 4096
      
      # Map sine value from -4096..4096 to 0..100
      self.value_buffer[i] = tasmota.scale_int(sine_value, -4096, 4096, 0, 100)
      i += 1
    end
  end
end

# Gradient pattern animation - creates shifting gradient patterns
#@ solidify:PaletteGradientAnimation,weak
class PaletteGradientAnimation : PalettePatternAnimation
  # Static definitions of parameters with constraints
  static var PARAMS = {
    # Gradient-specific parameters only
    "shift_period": {"min": 1, "default": 10000}
  }
  
  # Initialize a new gradient pattern animation
  #
  # @param engine: AnimationEngine - Required animation engine reference
  def init(engine)
    # Call parent constructor
    super(self).init(engine)
    
    # Set default name
    self.name = "palette_gradient"
  end
  
  # Override _update_value_buffer to generate gradient pattern directly
  def _update_value_buffer(time_ms)
    # Cache parameter values for performance
    var shift_period = self.shift_period
    var strip_length = self.engine.get_strip_length()
    
    # Resize buffer if strip length changed
    if size(self.value_buffer) != strip_length
      self.value_buffer.resize(strip_length)
    end
    
    # Calculate the shift position using scale_uint for better precision
    var position = tasmota.scale_uint(time_ms % shift_period, 0, shift_period, 0, 1000) / 1000.0
    var offset = int(position * strip_length)
    
    # Calculate values for each pixel
    var i = 0
    while i < strip_length
      # Calculate the gradient value (0-100) using scale_uint
      var pos_in_frame = (i + offset) % strip_length
      self.value_buffer[i] = tasmota.scale_uint(pos_in_frame, 0, strip_length - 1, 0, 100)
      i += 1
    end
  end
end

# Value meter pattern animation - creates meter/bar patterns based on a value function
#@ solidify:PaletteMeterAnimation,weak
class PaletteMeterAnimation : PalettePatternAnimation
  # Static definitions of parameters with constraints
  static var PARAMS = {
    # Meter-specific parameters only
    "value_func": {"default": nil, "type": "function"}
  }
  
  # Initialize a new meter pattern animation
  #
  # @param engine: AnimationEngine - Required animation engine reference
  def init(engine)
    # Call parent constructor
    super(self).init(engine)
    
    # Set default name
    self.name = "palette_meter"
  end
  
  # Override _update_value_buffer to generate meter pattern directly
  def _update_value_buffer(time_ms)
    # Cache parameter values for performance
    var value_func = self.value_func
    if value_func == nil
      return
    end
    
    var strip_length = self.engine.get_strip_length()
    
    # Resize buffer if strip length changed
    if size(self.value_buffer) != strip_length
      self.value_buffer.resize(strip_length)
    end
    
    # Get the current value
    var current_value = value_func(time_ms, self)
    
    # Calculate the meter position using scale_uint for better precision
    var meter_position = tasmota.scale_uint(current_value, 0, 100, 0, strip_length)
    
    # Calculate values for each pixel
    var i = 0
    while i < strip_length
      # Return 100 if pixel is within the meter, 0 otherwise
      self.value_buffer[i] = i < meter_position ? 100 : 0
      i += 1
    end
  end
end

return {
  'palette_pattern_animation': PalettePatternAnimation,
  'palette_wave_animation': PaletteWaveAnimation,
  'palette_gradient_animation': PaletteGradientAnimation,
  'palette_meter_animation': PaletteMeterAnimation
}