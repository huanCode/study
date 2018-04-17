|field|位|描述
-|-|-
table ID|8b|PAT表固定为0x00
section_syntax_indicator|1b|固定为1
reserved|2b|固定为1
section_length|12b|后面数据的长度[transport_stream_id，CRC32]

# 基本概念
>系统编码:传送流(TS packet)和程序流(PS packet),目前主要使用传送流;</br>
传送流:固定长度

## PSI table
table| 中文名|格式|table_id
-|-|-|-
PAT|程序关联表|标准规定|0x00
PMT|TS程序映射表|标准规定|0x02
CAT|条件访问表|标准规定|0x01
NIT|网络信息表|自定义|其他值自定义


## ES流
> ES流（Elementary Stream）：基本码流，不分段的音频、视频或其他信息的连续码流。

## PES流
>  PES流：把基本流ES分割成段，并加上相应头文件打包成形的打包基本码流。

## TS packet
<table>
    <tr>
        <td>header</td>
        <td>adaptation</td>
        <td>payload</td>
    </tr>
    <tr>
        <td>4 byte</td>
        <td colspan="2">184 byte</td>
    </tr>
</table>

>   packet:目前主要大小为188byte







> payload的内容就是PES;当PES长度超过payload时,分割成成几段,按顺序放入packet;
当PES长度小于payload时,adaptation填充未填满字节

>当payload时tables时,当table要分段时table的开始的payload的第一个字节为pointer_field</br>
pointer_field表示table在目前payload开始的偏移量,一般这个偏移量可以扔掉</br>
非table的音视频PES是没有pointer_field

# 传送流分组层field含义
- payload_unit_start_indicator
> 1、当PES长度 < payload长度，payload_unit_start_indicator = 1 </br>
2、当PES长度大于 > payload长度,比如分成3个packet0、packet1、packet2,那么packet0的payload_unit_start_indicator设1,packet1、packet2设置0；</br>
从以上知道,payload_unit_start_indicator的主要作用是用来表明该payload是否为PES的开始


# PID分配
包|PID
-|-|
PAT| 0x0000


# 结构
- TS packet
  - PAT
      - PMT
          - video PES
          - audio PES
      - NIT
- PS packet

# TS packet结构

<table>
    <tr>
        <td colspan="2">188 bytes</td>
    </tr>
    <tr>
        <td>header</td>
        <td>payload</td>
    </tr>
</table>

<table>
    <tr>
        <td colspan="9">Ts packet header结构</td>
    </tr>
    <tr>
        <td colspan="8">4 bytes</td>
        <td colspan="8">unknow bytes</td>
    </tr>
    <tr>
        <td>8 bits</td>
        <td>1 byte</td>
        <td>1 byte</td>
        <td>1 byte</td>
        <td>13 bits</td>
        <td>2 bits</td>
        <td>2 bits</td>
        <td>4 bits</td>
        <td></td>
    </tr>
        <tr>
        <td>sync byte</td>
        <td>transport error indicator</td>
        <td>payload unit start indicator</td>
        <td>transport priority</td>
        <td>PID</td>
        <td>transport scrambling control</td>
        <td>adaptation field control</td>
        <td>continuity counter</td>
        <td>adaptation field</td>
    </tr>
</table>
