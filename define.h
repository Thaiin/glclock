#define _USE_MATH_DEFINES

#define WINDOW_NAME1 "Clock"
#define WINDOW_NAME2 "Analog Clock"
#define WINDOW_NAME3 "Is this a Clock?"

#define SQ 360
#define SSQ 180
#define RENEWALTIME 100

// Windowの最低値
#define WINDOW_WIDTHSIZE 500
#define WINDOW_HEIGHTSIZE 400

// デジタル時計の表示位置 (固定)
#define PRINTTIME_W 20
#define PRINTTIME_H 40

// 上から時計周りに360等分したの時計の中心 
#define MINICIRCLE_POS_SEC 50
#define MINICIRCLE_POS_DAY 230
#define MINICIRCLE_AROUNDPOS_SEC 60
#define MINICIRCLE_AROUNDPOS_DAY 120

// 針の大きさ
#define SECPOINT 2
#define MINPOINT 3
#define HOURPOINT 4
#define CENTERPOINT 8
#define MINI_CENTERPOINT 4

// white がメイン時の色
#define WHITER 229
#define WHITEG 235
#define WHITEB 235
#define SEC_MINIHAND1_R 66
#define SEC_MINIHAND1_G 114
#define SEC_MINIHAND1_B 222

// black がメイン時の色
#define BLACKR 3
#define BLACKG 4
#define BLACKB 20
#define SEC_MINIHAND2_R 222
#define SEC_MINIHAND2_G 174
#define SEC_MINIHAND2_B 66

// グローバルにある引数の設定
#define DISABLE 0
#define ABLE 1

#define MODE1 1
#define MODE2 2
#define MODE3 3

#define ONEDAY 24
#define HALFDAY 12

#define WHITE 0
#define BLACK 1