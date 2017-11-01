
    MediaFormat mFormat = MediaFormat.createVideoFormat(strMime, iWidth, iHeight);
    //KEY_MAX_INPUT_SIZE设置不能超出mediacodec内部计算的最大值，如果超出了会导致mediacodec出现问题crash、anr等
    //由于无法知道mediacodec底层如何计算也无法获取内部的最大值，所以这里注释掉设置，使用mediacodec内部计算的默认值
    //mFormat.setInteger(MediaFormat.KEY_MAX_INPUT_SIZE, iMaxInputSize);

    //KEY_PUSH_BLANK_BUFFERS_ON_STOP配置用来设置结束播放后是否清屏，如果设置为1表示stop后会清掉屏幕上
    //最后一帧画面，如果设置为0表示stop后不清屏保留最后一帧花屏在屏幕上
    mFormat.setInteger(MediaFormat.KEY_PUSH_BLANK_BUFFERS_ON_STOP, Configurations.bClearScreenWhenStop?1:0);
    mFormat.setByteBuffer("csd-0", sps);
    mFormat.setByteBuffer("csd-1", pps);

    String mimeType = "video/avc";
    MediaCodec mCodec = MediaCodec.createDecoderByType(mimeType);
    mCodec.configure(mFormat, mSurface, null, 0);
    //自动填充屏幕大小
    mCodec.setVideoScalingMode(MediaCodec.VIDEO_SCALING_MODE_SCALE_TO_FIT);
    mCodec.start();

    ByteBuffer[] mCodecInputBuffers = mCodec.getInputBuffers();
    ByteBuffer[] mCodecOutputBuffers = mCodec.getOutputBuffers();

    while(true)
    {
         //1、timeoutUs > 0,等
         //2、timeoutUs = 0,立即返回
         //3、timeoutUs < 0,无限等待
         long timeoutUs = 1000;
         int inputBufferId = codec.dequeueInputBuffer(timeoutUs);
         if (inputBufferId >= 0) {
           ByteBuffer mCurInputByteBuffer = mCodecInputBuffers[inputBufferId];
           …
           codec.queueInputBuffer(inputBufferId, …);
         }
         int outputBufferId = codec.dequeueOutputBuffer(…);
         if (outputBufferId >= 0) {
           // outputBuffers[outputBufferId] is ready to be processed or rendered.
           …
           codec.releaseOutputBuffer(outputBufferId, …);
         } else if (outputBufferId == MediaCodec.INFO_OUTPUT_BUFFERS_CHANGED) {
           outputBuffers = codec.getOutputBuffers();
         } else if (outputBufferId == MediaCodec.INFO_OUTPUT_FORMAT_CHANGED) {
           // Subsequent data will conform to new format.
           MediaFormat format = codec.getOutputFormat();
         }
    }
    codec.stop();
    codec.release();

#网上例子
      FileInputStream in = new FileInputStream("/sdcard/sample.ts");
      String mimeType = "video/avc";
      MediaCodec decoder = MediaCodec.createDecoderByType(mimeType);
      MediaFormat format = MediaFormat.createVideoFormat(mimeType, 1920, 1080);
      byte[] header_sps = { 0, 0, 0, 1, 103, 100, 0, 40, -84, 52, -59, 1, -32, 17, 31, 120, 11, 80, 16, 16, 31, 0, 0, 3, 3, -23, 0, 0, -22, 96, -108 };
      byte[] header_pps = { 0, 0, 0, 1, 104, -18, 60, -128 };
      format.setByteBuffer("csd-0", ByteBuffer.wrap(header_sps));
      format.setByteBuffer("csd-1", ByteBuffer.wrap(header_pps));
      format.setInteger(MediaFormat.KEY_MAX_INPUT_SIZE, 1920 * 1080);
      format.setInteger("durationUs", 63446722);

      decoder.configure(format, surface, null, 0);
      decoder.start();

      ByteBuffer[] inputBuffers = decoder.getInputBuffers();
      ByteBuffer[] outputBuffers = decoder.getOutputBuffers();
      BufferInfo info = new BufferInfo();
      boolean isEOS = false;
      long startMs = System.currentTimeMillis();

      while (!Thread.interrupted()) {
          if (!isEOS) {
              int inIndex = decoder.dequeueInputBuffer(1000);
              if (inIndex >= 0) {
                  byte buffer2[] = new byte[18800 * 8 * 8 * 8];
                  ByteBuffer buffer = inputBuffers[inIndex];
                  int sampleSize;
                  sampleSize = in.read(buffer2, 0, 18800 * 4);

                  buffer.clear();
                  buffer.put(buffer2, 0, sampleSize);
                  buffer.clear();
                  if (sampleSize < 0) {
                      decoder.queueInputBuffer(inIndex, 0, 0, 0, MediaCodec.BUFFER_FLAG_END_OF_STREAM);
                      isEOS = true;
                  } else {
                      decoder.queueInputBuffer(inIndex, 0, sampleSize, 0, 0);
                  }
              }
          }

          int outIndex = decoder.dequeueOutputBuffer(info, 10000);
          switch (outIndex) {
          case MediaCodec.INFO_OUTPUT_BUFFERS_CHANGED:
              Log.d("DecodeActivity", "INFO_OUTPUT_BUFFERS_CHANGED");
              outputBuffers = decoder.getOutputBuffers();
              break;
          case MediaCodec.INFO_OUTPUT_FORMAT_CHANGED:
              Log.d("DecodeActivity", "New format " + decoder.getOutputFormat());
              break;
          case MediaCodec.INFO_TRY_AGAIN_LATER:
              Log.d("DecodeActivity", "dequeueOutputBuffer timed out! " + info);
              break;
          default:
              ByteBuffer buffer = outputBuffers[outIndex];
              Log.v("DecodeActivity", "We can't use this buffer but render it due to the API limit, " + buffer);

              while (info.presentationTimeUs / 1000 > System.currentTimeMillis() - startMs) {
                  try {
                      sleep(10);
                  } catch (InterruptedException e) {
                      e.printStackTrace();
                      break;
                  }
              }
              decoder.releaseOutputBuffer(outIndex, true);
              break;
          }

          if ((info.flags & MediaCodec.BUFFER_FLAG_END_OF_STREAM) != 0) {
              Log.d("DecodeActivity", "OutputBuffer BUFFER_FLAG_END_OF_STREAM");
              break;
          }
      }

      decoder.stop();
      decoder.release();
