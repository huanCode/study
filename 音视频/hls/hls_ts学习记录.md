|field|位|描述
-|-|-
table ID|8b|PAT表固定为0x00
section_syntax_indicator|1b|固定为1
reserved|2b|固定为1
section_length|12b|后面数据的长度[transport_stream_id，CRC32]

# 基本概念
## ES流
> ES流（Elementary Stream）：基本码流，不分段的音频、视频或其他信息的连续码流。

## PES流
>  PES流：把基本流ES分割成段，并加上相应头文件打包成形的打包基本码流。

## packet
packet|packet|....
-|-|-
> packet:目前主要大小为188byte

packet内部结构如下:
header|adaptation|payload
-|-|-
> payload的内容就是PES;当PES长度超过payload时,分割成成几段,按顺序放入packet;
当PES长度小于payload时,adaptation填充未填满字节



# 传送流分组层field含义
- payload_unit_start_indicator
> 当PES长度 < payload长度，payload_unit_start_indicator = 1 </br>
当PES长度大于 > payload长度,比如分成3个packet0、packet1、packet2,那么packet0的payload_unit_start_indicator设1,packet1、packet2设置0；</br>
从以上知道,payload_unit_start_indicator的主要作用是用来表明该payload是否为PES的开始


# PID分配
包|PID
-|-|
PAT| 0x0000


# 结构
- PAT
    - PMT
        - video PES
        - audio PES
