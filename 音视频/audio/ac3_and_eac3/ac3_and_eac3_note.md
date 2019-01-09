1.ac3和eac3从容器里解析出来,可能是由几个帧合成的，
比如一个帧是100,解析出来的250,那么这其中就有2帧是完整的,其中50需要再从容器去获取,然后拼接起来成一个完整的帧，
于是就需要对每个parseFrame,进行拆分出一个个完整的audio frame,以及从前后的parseFrame,拼接起不完整的audio Frame



2.从容器解析出来的parseFrame,可能需要与后面的parseFrame拼接起来
