package com.example.myapplication;

import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.Vibrator;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {
    TextView mTvBluetoothStatus;
    TextView mTvtemp;
    TextView mTvgas;
    TextView tvcall;
    TextView mTvtemp_set;
    TextView mTvgas_set;
    ImageButton mBtnBluetoothOn;
    ImageButton btncall;
    ImageButton mBtnBluetoothOff;
    Button mBtnConnect;
    Button mBtncctv;
    public static Context mContext = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        Vibrator vibrator = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);
        vibrator.vibrate(1500); //1.5초간 진동
        ActionBar actionBar = getSupportActionBar();
        actionBar.hide();
        mTvBluetoothStatus = (TextView) findViewById(R.id.tvBluetoothStatus);
        mTvtemp = (TextView) findViewById(R.id.tvtemp);
        mTvgas = (TextView) findViewById(R.id.tvgas);
        mTvtemp_set = (TextView) findViewById(R.id.tvtemp_set);
        mTvgas_set = (TextView) findViewById(R.id.tvgas_set);
        mBtnBluetoothOn = (ImageButton) findViewById(R.id.btnBluetoothOn);
        mBtnBluetoothOff = (ImageButton) findViewById(R.id.btnBluetoothOff);
        mBtnConnect = (Button) findViewById(R.id.btnConnect);
        mBtncctv = (Button) findViewById(R.id.btnSendData);
        btncall = (ImageButton) findViewById(R.id.btncall);
        tvcall = (TextView) findViewById(R.id.tvcall);

        Intent intent = getIntent();
        String temp = intent.getExtras().getString("temp");
        String gas = intent.getExtras().getString("gas");
        mTvtemp_set.setText(temp.concat("˚C"));
        mTvgas_set.setText(gas.concat("ppm"));

        if(ContextCompat.checkSelfPermission(this, Manifest.permission.CALL_PHONE) != PackageManager.PERMISSION_GRANTED)
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.CALL_PHONE}, 1);

        mBtncctv.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(MainActivity2.this, CCTV.class);
                startActivity(intent);
            }
        });

        btncall.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent mIntent = new Intent(Intent.ACTION_CALL, Uri.parse("tel:119"));
                startActivity(mIntent);
            }
        });

    }
}
