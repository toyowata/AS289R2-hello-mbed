# AS289R2-hello-mbed

The AS-289R2 is the industry's most advanced two-inch thermal printer. You can directly connect the thermal printer to your mbed platforms.

https://os.mbed.com/components/AS-289R2-Thermal-Printer-Shield/

## Pinout

<img width="600" src="https://os.mbed.com/media/components/pinouts/jumper.png">

## Notes

The AS-289R2 is the industry's most advanced two-inch thermal printer. You can directly connect the thermal printer to your mbed platforms.

http://www.nada.co.jp/as289r2/en/product.html

|Item|Description|
|---|---|
|Model|AS-289R2|
|RoHS|RoHS compliant|
|Printing method|Thermal-line dot method|
|Supply Voltage	|5V (-5% to +5%)|
|Average current|2A|
|Interface|3.3V or 5V level (JP5)|
||9600 or 38400bps (JP6)|
||Serial or Serial2 (JP2)|
||8Bit NonParity 1Stop|
|Resolution Ratio|8dots/mm (384dots/line)|
|Print Speed|25mm/sec|
|Effective printing area|48mm|
|Character types|UTF8|
||Alphanumeric, katakana: 160types|
||JIS Kanji level1: 2965types|
||JIS Kanji level2: 3388types|
||non-Kanji: 524types|
|Character dimensions (HxW)|8x16dots: ANK|
||12x24dots: ANK (Default)|
||16x16dots: ANK, Kanji level1 and level2|
||24x24dots: ANK, Kanjii level1 and level2 (Default)|
||48x96dots: 0-9 A-Z|
|Barcode|QR, JAN(13,8), 2of5(ITF), 2of7(NW7), 3of9(CODE39), UPC-A|
|Ambient temperature|Operation guarantee: 0°C to 50°C, print quality guarantee: 5°C to 40°C|
|Relative humidity|print quality guarantee: 35% RH to 80% RH|
|Reliability|Print head : 50km|
||MCBF : 30 million lines|
|Accessory Lists|Thermal Paper (58mm Width x 50mm Diameter)|
||Wire Harness (L=1m JST VHR-2N 1=Red 2=Black)|
||Thermal Paper Roll Holder|


## Connectivity
You can connect the AS-289R2 Thermal Print Shield to Arduino shield form factor mbed plafroms.

#### Note:
To use D1 serial pin of the Nucleo platforms, you have to remove SB13 and SB14 then bridge SB62 and SB63. This will enable the processor to communicate with the shield using the default serial connection.

## References
* You can purchase the AS-289R2 from Switch Science international web shop [here](https://international.switch-science.com/catalog/2553/).
* [AS-289R2 product page](http://www.nada.co.jp/as289r2/en/product.html)
