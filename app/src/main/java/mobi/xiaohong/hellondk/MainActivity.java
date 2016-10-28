package mobi.xiaohong.hellondk;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    private ImageView mImage;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        mImage = (ImageView) findViewById(R.id.main_iamge);
        tv.setText(stringFromJNI());

        Bitmap bitmap =
                BitmapFactory.decodeResource(getResources(), R.mipmap.ic_launcher);

        int height = bitmap.getHeight();
        int width = bitmap.getWidth();
        int size = height * width;
        int[] color = new  int[size];
        bitmap.getPixels(color, 0, width, 0, 0, width, height);
        int[] colors = NativeHelper.convertBitmap(color, width, height);
        bitmap.recycle();
        bitmap = bitmap.createBitmap(colors, width,height, Bitmap.Config.ARGB_8888);
        mImage.setImageBitmap(bitmap);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public void btnGetKey(View view) {
        String appkey = NativeHelper.getAppkey();
        String secret = NativeHelper.getAppSecret();
        Toast.makeText(this, "appkey: " + appkey
                + "  appsecret: " + secret, Toast.LENGTH_SHORT).show();

        NativeHelper.sayHello("冯红静");
    }
}
