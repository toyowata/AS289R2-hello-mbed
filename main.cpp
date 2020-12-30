/* AS289R2 library test program for mbed OS
 * Copyright (c) 2016-2020, Toyomasa Watarai
 * SPDX-License-Identifier: Apache-2.0
*/
 
#include "mbed.h"
#include "AS289R2.h"
 
DigitalOut led1(LED1);
AS289R2 tp(AS289R2_TX, AS289R2_RX);
 
const char url[] = "https://os.mbed.com/components/AS-289R2-Thermal-Printer-Shield/";
 
void AS289R2_demo()
{
    tp.initialize();
    tp.putLineFeed(2);
 
    tp.printf("** Thermal Printer Shield **\r\r");
 
    tp.setDoubleSizeWidth();
    tp.printf("  AS-289R2\r\r");
    tp.clearDoubleSizeWidth();
 
    tp.printf("日本語文字列の印字テスト:24x24\r");
    tp.setKanjiFont(AS289R2::KANJI_16x16);
    tp.setANKFont(AS289R2::ANK_8x16);
    tp.printf("日本語文字列の印字テスト:16x16\r\r");
 
    tp.setKanjiFont(AS289R2::KANJI_DEFAULT);
    tp.setANKFont(AS289R2::ANK_DEFAULT);
    tp.setDoubleSizeWidth();
    tp.printf("ABCDEFG 0123456789\r");
    tp.clearDoubleSizeWidth();
 
    tp.setDoubleSizeHeight();
    tp.printf("ABCDEFG 0123456789\r");
    tp.clearDoubleSizeHeight();
 
    tp.putLineFeed(2);
 
    tp.setANKFont(AS289R2::ANK_8x16);
    tp.printf("8x16: Test 012345 ｱｲｳｴｵ\r\r");
    tp.setANKFont(AS289R2::ANK_12x24);
    tp.printf("12x24: Test 012345 ｱｲｳｴｵ\r\r");
    tp.setANKFont(AS289R2::ANK_16x16);
    tp.printf("16x16: Test 012345 ｱｲｳｴｵ\r\r");
    tp.setANKFont(AS289R2::ANK_24x24);
    tp.printf("24x24: Test 012345 ｱｲｳｴｵ\r\r");
    tp.putLineFeed(1);
 
    tp.setANKFont(AS289R2::ANK_8x16);
    tp.printf("QR\r");
    tp.printQRCode(AS289R2::QR_ERR_LVL_M, url);
    tp.printf("\r%s\r", url);
    tp.putLineFeed(2);
 
    tp.printf("UPC-A\r");
    tp.printBarCode(AS289R2::BCODE_UPC_A, "01234567890");
    tp.putLineFeed(4);
 
#if 0
    // LineSpaceing
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.setLineSpaceing(20);
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.defaultLineSpaceing();
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.putLineFeed(4);
 
    // PrintDirection
    tp.setPrintDirection(1);
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.setPrintDirection(0);
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
 
    // PaperFeed
    tp.putPaperFeed(200);
 
    // InterCharacterSpace
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.setInterCharacterSpace(8);
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.defaultInterCharacterSpace();
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.putLineFeed(4);
 
    // PrintPosition
    tp.printf("ABCDE\r");
    tp.putPrintPosition(5);
    tp.printf("ABCDE\r");
    tp.putPrintPosition(15);
    tp.printf("ABCDE\r");
    tp.putPrintPosition(25);
    tp.printf("ABCDE\r");
    tp.printf("ABCDE\r");
    tp.putLineFeed(4);
 
    // Script
    tp.printf("123cm");
    tp.setScript(1);
    tp.printf("2");
    tp.clearScript();
    tp.printf("\r");
    tp.printf("123cm");
    tp.setScript(2);
    tp.printf("5");
    tp.clearScript();
    tp.printf("\r");
    tp.putLineFeed(4);
 
    // QuadrupleSize
    tp.setQuadrupleSize();
    tp.printf("ABCDE\r");
    tp.clearQuadrupleSize();
    tp.printf("ABCDE\r");
 
    // Enlargement
    tp.setEnlargement(1, 4);
    tp.printf("ABCDE\r");
    tp.setEnlargement(2, 4);
    tp.printf("ABCDE\r");
    tp.setEnlargement(3, 4);
    tp.printf("ABCDE\r");
    tp.setEnlargement(4, 4);
    tp.printf("ABCDE\r");
    tp.clearEnlargement();
    tp.printf("ABCDE\r");
 
    // BarCodeHeight
    tp.setBarCodeHeight(10);
    tp.printf("JAN13\r");
    tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");
    tp.setBarCodeHeight(20);
    tp.printf("JAN13\r");
    tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");
    tp.defaultBarCodeHeight();
    tp.printf("JAN13\r");
    tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");
    tp.putLineFeed(4);
 
    // BarCodeBarSize
    tp.setBarCodeBarSize(3,5);
    tp.printf("JAN13\r");
    tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");
    tp.defaultBarCodeBarSize();
    tp.printBarCode(AS289R2::BCODE_JAN13, "123456789012");
    tp.putLineFeed(4);
#endif
}
 
 
int main()
{
    AS289R2_demo();
    while (true) {
        led1 = !led1;
        thread_sleep_for(500);
    }
}
 