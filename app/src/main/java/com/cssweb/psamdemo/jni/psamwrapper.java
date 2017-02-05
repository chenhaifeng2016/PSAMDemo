package com.cssweb.psamdemo.jni;

/**
 * Created by chenhf on 16-6-30.
 */
public class psamwrapper {

    public native String open();

    static {
        System.loadLibrary("psamwrapper");
    }
}
