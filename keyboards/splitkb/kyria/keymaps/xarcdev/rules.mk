# =============================================================================
# Board Configuration
# =============================================================================
CONVERT_TO = liatris

# =============================================================================
# Build Options
# =============================================================================
EXTRAFLAGS += -flto
LTO_ENABLE = yes

# =============================================================================
# Core Features - Enabled
# =============================================================================
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Audio control and System control
KEY_LOCK_ENABLE = yes
MOUSEKEY_ENABLE = yes       # Mouse keys
TAP_DANCE_ENABLE = yes

# =============================================================================
# Core Features - Disabled
# =============================================================================
BLUETOOTH_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
DYNAMIC_MACRO_ENABLE = no
LEADER_ENABLE = no

# =============================================================================
# Display & Lighting - Disabled
# =============================================================================
ENCODER_ENABLE = no         # Rotary encoders
LED_UPDATE_USER_ENABLE = no
OLED_ENABLE = no
RGBLIGHT_ENABLE = no        # RGB underglow
WPM_ENABLE = no

# =============================================================================
# Custom Features
# =============================================================================
SRC += features/layer_lock.c
