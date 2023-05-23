|module name|base addr|offset|reg name|bit filed|attribute|description|
|---------|----------|----------|----------|----------|----------|----------|
AD5544_Ctrl|0x100|0x0|not named|[15:0]|W| DAC_OUT_0|
^|^|0x0|not named|[15:0]|R| DAC_OUT_0|
^|^|0x4|not named|[15:0]|W| DAC_OUT_1|
^|^|0x4|not named|[15:0]|R| DAC_OUT_1|
^|^|0x8|not named|[15:0]|W| DAC_OUT_2|
^|^|0x8|not named|[15:0]|R| DAC_OUT_2|
^|^|0xc|not named|[15:0]|W| DAC_OUT_3|
^|^|0xc|not named|[15:0]|R| DAC_OUT_3|
^|^|0x10|not named|[0:0]|W| Trigger_0|
^|^|0x10|not named|[0:0]|R| Trigger_0|
^|^|0x14|not named|[15:0]|W| DAC_OUT_4|
^|^|0x14|not named|[15:0]|R| DAC_OUT_4|
^|^|0x18|not named|[15:0]|W| DAC_OUT_5|
^|^|0x18|not named|[15:0]|R| DAC_OUT_5|
^|^|0x1c|not named|[15:0]|W| DAC_OUT_6|
^|^|0x1c|not named|[15:0]|R| DAC_OUT_6|
^|^|0x20|not named|[15:0]|W| DAC_OUT_7|
^|^|0x20|not named|[15:0]|R| DAC_OUT_7|
^|^|0x24|not named|[0:0]|W| Trigger_1|
^|^|0x24|not named|[0:0]|R| Trigger_1|
^|^|0x28|not named|[15:0]|W| DAC_OUT_8|
^|^|0x28|not named|[15:0]|R| DAC_OUT_8|
^|^|0x2c|not named|[15:0]|W| DAC_OUT_9|
^|^|0x2c|not named|[15:0]|R| DAC_OUT_9|
^|^|0x30|not named|[15:0]|W| DAC_OUT_10|
^|^|0x30|not named|[15:0]|R| DAC_OUT_10|
^|^|0x34|not named|[15:0]|W| DAC_OUT_11|
^|^|0x34|not named|[15:0]|R| DAC_OUT_11|
^|^|0x38|not named|[0:0]|W| Trigger_2|
^|^|0x38|not named|[0:0]|R| Trigger_2|
AD7606_Ctrl|0x200|0x0|not named|[15:0]|R| ad7606_data_0|
^|^|0x4|not named|[15:0]|R| ad7606_data_1|
^|^|0x8|not named|[15:0]|R| ad7606_data_2|
^|^|0xc|not named|[15:0]|R| ad7606_data_3|
^|^|0x10|not named|[15:0]|R| ad7606_data_4|
^|^|0x14|not named|[15:0]|R| ad7606_data_5|
^|^|0x18|not named|[15:0]|R| ad7606_data_6|
^|^|0x1c|not named|[15:0]|R| ad7606_data_7|
Grating_Ctrl|0x300|0x0|not named|[15:0]|R| BISS_C Postion bit(31:16)|
^|^|0x2|not named|[15:0]|R| BISS_C Postion bit(15:0)|
^|^|0x4|not named|[15:0]|R| Encoder Postion bit(31:16)|
^|^|0x6|not named|[15:0]|R| Encoder Postion bit(15:0)|
^|^|0xa|not named|[5:0]|R| Endat Postion bit(38:32)|
^|^|0xc|not named|[15:0]|R| Endat Postion bit(31:16)|
^|^|0xe|not named|[15:0]|R| Endat Postion bit(15:0)|
^|^|0x10|not named|[0:0]|R| encoder_zero_singal|
^|^|0x14|not named|[0:0]|W| encoder_postion_reset|
^|^|0x14|not named|[0:0]|R| encoder_postion_reset|
^|^|0x18|not named|[0:0]|R| endat_index|
^|^|0x1c|not named|[1:0]|W| config grating mode,0---bissc,1----encoder,2----endat|
^|^|0x1c|not named|[1:0]|R| config grating mode,0---bissc,1----encoder,2----endat|
^|^|0x20|not named|[0:0]|W| encoder zero clear mode,0---AUTO,1----MANUAL|
^|^|0x20|not named|[0:0]|R| encoder zero clear mode,0---AUTO,1----MANUAL|
^|^|0x24|not named|[15:0]|W| encoder zero hold time_cnt, time= clk * time_cnt|
^|^|0x24|not named|[15:0]|R| encoder zero hold time_cnt, time= clk * time_cnt|
Grating_Ctrl|0x400|0x0|not named|[15:0]|R| BISS_C Postion bit(31:16)|
^|^|0x2|not named|[15:0]|R| BISS_C Postion bit(15:0)|
^|^|0x4|not named|[15:0]|R| Encoder Postion bit(31:16)|
^|^|0x6|not named|[15:0]|R| Encoder Postion bit(15:0)|
^|^|0xa|not named|[5:0]|R| Endat Postion bit(38:32)|
^|^|0xc|not named|[15:0]|R| Endat Postion bit(31:16)|
^|^|0xe|not named|[15:0]|R| Endat Postion bit(15:0)|
^|^|0x10|not named|[0:0]|R| encoder_zero_singal|
^|^|0x14|not named|[0:0]|W| encoder_postion_reset|
^|^|0x14|not named|[0:0]|R| encoder_postion_reset|
^|^|0x18|not named|[0:0]|R| endat_index|
^|^|0x1c|not named|[1:0]|W| config grating mode,0---bissc,1----encoder,2----endat|
^|^|0x1c|not named|[1:0]|R| config grating mode,0---bissc,1----encoder,2----endat|
^|^|0x20|not named|[0:0]|W| encoder zero clear mode,0---AUTO,1----MANUAL|
^|^|0x20|not named|[0:0]|R| encoder zero clear mode,0---AUTO,1----MANUAL|
^|^|0x24|not named|[15:0]|W| encoder zero hold time_cnt, time= clk * time_cnt|
^|^|0x24|not named|[15:0]|R| encoder zero hold time_cnt, time= clk * time_cnt|
Bissc_Ctrl|0x500|0x0|not named|[15:0]|R| bissc_data 0 [31:16]|
^|^|0x2|not named|[15:0]|R| bissc_data 0 [15:0]|
^|^|0x4|not named|[15:0]|R| bissc_data 1 [31:16]|
^|^|0x6|not named|[15:0]|R| bissc_data 1 [15:0]|
^|^|0x8|not named|[15:0]|R| bissc_data 2 [31:16]|
^|^|0xa|not named|[15:0]|R| bissc_data 2 [15:0]|
^|^|0xc|not named|[15:0]|R| bissc_data 3 [31:16]|
^|^|0xe|not named|[15:0]|R| bissc_data 3 [15:0]|

