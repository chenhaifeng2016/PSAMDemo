package com.cssweb.psamdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.cssweb.psamdemo.jni.psamwrapper;

public class MainActivity extends AppCompatActivity {

    private TextView tvTest;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        psamwrapper psam = new psamwrapper();

        tvTest = (TextView) findViewById(R.id.test);

        tvTest.setText(psam.open());

    }
}
