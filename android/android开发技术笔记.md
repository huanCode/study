##应用开机自启动
1. 创建广播类
作用:创建开机后的广播通知
```java
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.widget.Toast;

public class AutoStartBroadcastReceiver extends BroadcastReceiver {

    static final String action_boot ="android.intent.action.BOOT_COMPLETED";
    @Override
    public void onReceive(Context context, Intent intent) {
        if (intent.getAction().equals(action_boot)){
            Toast.makeText(context, "boot completed action has got", Toast.LENGTH_LONG).show();
            Intent sayHelloIntent=new Intent(context,LoginActivity.class);
            sayHelloIntent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);

            context.startActivity(sayHelloIntent);
        }
    }
}

```
注意:其中的LoginActivity改为自己项目里对应的activity继承类

2.  在AndroidManifest.xml 添加权限
```xml
在manifest 中添加如下属性,确保app安装在sd卡里
android:installLocation="internalOnly"
```

```xml
添加广播权限:
<uses-permission android:name="android.permission.RECEIVE_BOOT_COMPLETED" />
```

```xml
添加在 application 标签里
<receiver android:name=".ui.AutoStartBroadcastReceiver">
    <intent-filter>
        <action android:name="android.intent.action.BOOT_COMPLETED"/>
    </intent-filter>
</receiver>
```

4. 注意事项
>小米盒子不能起作用,可能需要root


#2.显示时间
```java
        long time=System.currentTimeMillis();
        Date date=new Date(time);
        SimpleDateFormat format=new SimpleDateFormat("yyyy年MM月dd日 HH时mm分ss秒 EEEE");
        String strTime = format.format(date);
```


#3.获取存储空间大小
```java
    public static long getAvailableInternalMemorySize() {
    	File path = Environment.getDataDirectory();
    	StatFs stat = new StatFs(path.getPath());
    	long blockSize = stat.getBlockSize();
    	long availableBlocks = stat.getAvailableBlocks();

    	long size = availableBlocks * blockSize;
    	return availableBlocks * blockSize;
   }
```
