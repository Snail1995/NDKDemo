package mobi.xiaohong.hellondk;

/**
 * Created by XIAOHONG
 * Author: XIAOHONG.
 * Date: 2016/10/28.
 * Email ${EMAIL}
 */

public class NativeHelper {


    static {
        // 加载C代码库,
        System.loadLibrary("native-lib");
    }

    /**
     * 实现C 语言的调用入口, 需要用 C语言来实现
     *
     * @return
     */
    public static native String getAppkey();

    public static native String getAppSecret();

    /**
     * java  向c 传递参数, 并且返回结果
     *
     * @param a
     * @param b
     * @return
     */
    public static native int add(int a, int b);


    /**
     * java向 c 传递参数 , 并且没有返回值
     *
     * @param name
     */
    public static native void sayHello(String name);

    public static native int[] convertBitmap(int[] colors, int w, int h);

}
