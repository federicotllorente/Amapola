#pragma once

/* From GLFW/glfw3.h */

/* Printable keys */
#define AMPL_KEY_SPACE              32
#define AMPL_KEY_APOSTROPHE         39  /* ' */
#define AMPL_KEY_COMMA              44  /* , */
#define AMPL_KEY_MINUS              45  /* - */
#define AMPL_KEY_PERIOD             46  /* . */
#define AMPL_KEY_SLASH              47  /* / */
#define AMPL_KEY_0                  48
#define AMPL_KEY_1                  49
#define AMPL_KEY_2                  50
#define AMPL_KEY_3                  51
#define AMPL_KEY_4                  52
#define AMPL_KEY_5                  53
#define AMPL_KEY_6                  54
#define AMPL_KEY_7                  55
#define AMPL_KEY_8                  56
#define AMPL_KEY_9                  57
#define AMPL_KEY_SEMICOLON          59  /* ; */
#define AMPL_KEY_EQUAL              61  /* = */
#define AMPL_KEY_A                  65
#define AMPL_KEY_B                  66
#define AMPL_KEY_C                  67
#define AMPL_KEY_D                  68
#define AMPL_KEY_E                  69
#define AMPL_KEY_F                  70
#define AMPL_KEY_G                  71
#define AMPL_KEY_H                  72
#define AMPL_KEY_I                  73
#define AMPL_KEY_J                  74
#define AMPL_KEY_K                  75
#define AMPL_KEY_L                  76
#define AMPL_KEY_M                  77
#define AMPL_KEY_N                  78
#define AMPL_KEY_O                  79
#define AMPL_KEY_P                  80
#define AMPL_KEY_Q                  81
#define AMPL_KEY_R                  82
#define AMPL_KEY_S                  83
#define AMPL_KEY_T                  84
#define AMPL_KEY_U                  85
#define AMPL_KEY_V                  86
#define AMPL_KEY_W                  87
#define AMPL_KEY_X                  88
#define AMPL_KEY_Y                  89
#define AMPL_KEY_Z                  90
#define AMPL_KEY_LEFT_BRACKET       91  /* [ */
#define AMPL_KEY_BACKSLASH          92  /* \ */
#define AMPL_KEY_RIGHT_BRACKET      93  /* ] */
#define AMPL_KEY_GRAVE_ACCENT       96  /* ` */
#define AMPL_KEY_WORLD_1            161 /* non-US #1 */
#define AMPL_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define AMPL_KEY_ESCAPE             256
#define AMPL_KEY_ENTER              257
#define AMPL_KEY_TAB                258
#define AMPL_KEY_BACKSPACE          259
#define AMPL_KEY_INSERT             260
#define AMPL_KEY_DELETE             261
#define AMPL_KEY_RIGHT              262
#define AMPL_KEY_LEFT               263
#define AMPL_KEY_DOWN               264
#define AMPL_KEY_UP                 265
#define AMPL_KEY_PAGE_UP            266
#define AMPL_KEY_PAGE_DOWN          267
#define AMPL_KEY_HOME               268
#define AMPL_KEY_END                269
#define AMPL_KEY_CAPS_LOCK          280
#define AMPL_KEY_SCROLL_LOCK        281
#define AMPL_KEY_NUM_LOCK           282
#define AMPL_KEY_PRINT_SCREEN       283
#define AMPL_KEY_PAUSE              284
#define AMPL_KEY_F1                 290
#define AMPL_KEY_F2                 291
#define AMPL_KEY_F3                 292
#define AMPL_KEY_F4                 293
#define AMPL_KEY_F5                 294
#define AMPL_KEY_F6                 295
#define AMPL_KEY_F7                 296
#define AMPL_KEY_F8                 297
#define AMPL_KEY_F9                 298
#define AMPL_KEY_F10                299
#define AMPL_KEY_F11                300
#define AMPL_KEY_F12                301
#define AMPL_KEY_F13                302
#define AMPL_KEY_F14                303
#define AMPL_KEY_F15                304
#define AMPL_KEY_F16                305
#define AMPL_KEY_F17                306
#define AMPL_KEY_F18                307
#define AMPL_KEY_F19                308
#define AMPL_KEY_F20                309
#define AMPL_KEY_F21                310
#define AMPL_KEY_F22                311
#define AMPL_KEY_F23                312
#define AMPL_KEY_F24                313
#define AMPL_KEY_F25                314
#define AMPL_KEY_KP_0               320
#define AMPL_KEY_KP_1               321
#define AMPL_KEY_KP_2               322
#define AMPL_KEY_KP_3               323
#define AMPL_KEY_KP_4               324
#define AMPL_KEY_KP_5               325
#define AMPL_KEY_KP_6               326
#define AMPL_KEY_KP_7               327
#define AMPL_KEY_KP_8               328
#define AMPL_KEY_KP_9               329
#define AMPL_KEY_KP_DECIMAL         330
#define AMPL_KEY_KP_DIVIDE          331
#define AMPL_KEY_KP_MULTIPLY        332
#define AMPL_KEY_KP_SUBTRACT        333
#define AMPL_KEY_KP_ADD             334
#define AMPL_KEY_KP_ENTER           335
#define AMPL_KEY_KP_EQUAL           336
#define AMPL_KEY_LEFT_SHIFT         340
#define AMPL_KEY_LEFT_CONTROL       341
#define AMPL_KEY_LEFT_ALT           342
#define AMPL_KEY_LEFT_WINDOWS       343
#define AMPL_KEY_LEFT_COMMAND       AMPL_KEY_LEFT_WINDOWS
#define AMPL_KEY_RIGHT_SHIFT        344
#define AMPL_KEY_RIGHT_CONTROL      345
#define AMPL_KEY_RIGHT_ALT          346
#define AMPL_KEY_RIGHT_WINDOWS      347
#define AMPL_KEY_RIGHT_COMMAND      AMPL_KEY_RIGHT_WINDOWS
#define AMPL_KEY_MENU               348
