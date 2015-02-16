package com.example.ali.bt_control;

import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnTouchListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Set;
import java.util.UUID;

public class MyActivity extends Activity {


    TextView myLabel;
    EditText myDevice;
    BluetoothAdapter btAdapter;
    BluetoothSocket btSocket;
    BluetoothDevice btDevice;
    OutputStream outStream;
    InputStream inStream;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_my);

        Button openButton = (Button) findViewById(R.id.open);
        Button forward = (Button) findViewById(R.id.forwardB);
        Button backward = (Button) findViewById(R.id.backwardB);
        Button left = (Button) findViewById(R.id.leftB);
        Button right = (Button) findViewById(R.id.rightB);
        Button on = (Button) findViewById(R.id.onB);
        Button off = (Button) findViewById(R.id.offB);
        Button lift = (Button) findViewById(R.id.liftB);
        Button low = (Button) findViewById(R.id.lowB);
        Button Close = (Button) findViewById(R.id.close);

        myLabel = (TextView) findViewById(R.id.label);
        myDevice = (EditText)findViewById(R.id.deviceName);

        // When the button is clicked it launches the findBT method which
        // detects if the bluetooth module is available
        // Finally once the findBT has determined that the bluetooth connection
        // is available it connects the two devices together
        openButton.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                try {
                    findBT();
                    openBT();
                } catch (IOException ex) {
                }
            }

        });


        //Just buttons that send the message to the Arduino and run which motor that the message is associated with
        forward.setOnTouchListener(new OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {

                if (event.getAction() == MotionEvent.ACTION_DOWN) {

                    try {
                        forwardButton();
                    } catch (IOException ex) {
                    }
                } else if (event.getAction() == MotionEvent.ACTION_UP) {

                    try {
                        stopMotor();
                    } catch (IOException ex) {
                    }
                }
                return false;
            }
            //return false;
        });

    backward.setOnTouchListener(new OnTouchListener() {
        @Override
        public boolean onTouch(View v, MotionEvent event) {

            if (event.getAction() == MotionEvent.ACTION_DOWN) {

                try {
                    backwardButton();
                } catch (IOException ex) {
                }
            } else if (event.getAction() == MotionEvent.ACTION_UP) {

                try {
                    stopMotor();
                } catch (IOException ex) {
                }
            }

            return false;
        }
        //return false;
    }

);

        left.setOnTouchListener(new OnTouchListener() {
@Override
public boolean onTouch(View v, MotionEvent event) {

        if (event.getAction() == MotionEvent.ACTION_DOWN) {

        try {
        leftButton();
        } catch (IOException ex) {
        }
        } else if (event.getAction() == MotionEvent.ACTION_UP) {

            try {
                stopMotor();
            } catch (IOException ex) {
            }
        }
    return false;
        }
        //return false;
        }

        );

        right.setOnTouchListener(new OnTouchListener() {
@Override
public boolean onTouch(View v, MotionEvent event) {

        if (event.getAction() == MotionEvent.ACTION_DOWN) {

        try {
        rightButton();
        } catch (IOException ex) {
        }
        } else if (event.getAction() == MotionEvent.ACTION_UP) {

            try {
                stopMotor();
            } catch (IOException ex) {
            }
        }
    return false;
        }
        //return false;
        }


 );


        on.setOnTouchListener(new OnTouchListener() {
@Override
public boolean onTouch(View v, MotionEvent event) {

        if (event.getAction() == MotionEvent.ACTION_DOWN) {

        try {
        onButton();
        } catch (IOException ex) {
        }
        } /*else if (event.getAction() == MotionEvent.ACTION_UP) {

					try {
						stopMotor();
					} catch (IOException ex) {
					}*/
    return false;
        }
        //return false;
        }


);

        off.setOnTouchListener(new OnTouchListener() {
@Override
public boolean onTouch(View v, MotionEvent event) {

        if (event.getAction() == MotionEvent.ACTION_DOWN) {

        try {
        offButton();
        } catch (IOException ex) {
        }
        }/* else if (event.getAction() == MotionEvent.ACTION_UP) {

					try {
						stopMotor();
					} catch (IOException ex) {
					}*/
    return false;
        }
        //return false;
        }

        );

        lift.setOnTouchListener(new OnTouchListener() {
@Override
public boolean onTouch(View v, MotionEvent event) {

        if (event.getAction() == MotionEvent.ACTION_DOWN) {

        try {
        liftButton();
        } catch (IOException ex) {
        }
        } /*else if (event.getAction() == MotionEvent.ACTION_UP) {

					try {
						stopMotor();
					} catch (IOException ex) {
					}*/
    return false;
        }
        //return false;
        }

        );

        low.setOnTouchListener(new OnTouchListener() {
@Override
public boolean onTouch(View v, MotionEvent event) {

        if (event.getAction() == MotionEvent.ACTION_DOWN) {

        try {
        lowButton();
        } catch (IOException ex) {
        }
        } /*else if (event.getAction() == MotionEvent.ACTION_UP) {

					try {
						stopMotor();
					} catch (IOException ex) {
					}*/
    return false;
        }
        //return false;
        }

        );

        Close.setOnClickListener(new View.OnClickListener() {

@Override
public void onClick(View v) {

        finish();
        System.exit(0);
        }
        });

        }


        //Looks for and connects to the bluetooth module
        void findBT() {
        btAdapter = BluetoothAdapter.getDefaultAdapter();
        if (btAdapter == null) {
        myLabel.setText("No bluetooth adapter available");
        }

        if (!btAdapter.isEnabled()) {
        Intent enableBluetooth = new Intent(
        BluetoothAdapter.ACTION_REQUEST_ENABLE);
        startActivityForResult(enableBluetooth, 0);
        }

        Set<BluetoothDevice> pairedDevices = btAdapter.getBondedDevices();
        if (pairedDevices.size() > 0) {
        for (BluetoothDevice device : pairedDevices) {
        String pairedDeviceName = myDevice.getText().toString();
        if (device.getName().equals(pairedDeviceName)) {
        btDevice = device;
        break;
        }
        }
        }
        myLabel.setText("Bluetooth Device Found");
        }

        // Connects the two devices together
        void openBT() throws IOException {
        UUID uuid = UUID.fromString("00001101-0000-1000-8000-00805f9b34fb"); // Standard
        // SerialPortService
        // ID
        btSocket = btDevice.createRfcommSocketToServiceRecord(uuid);
        btSocket.connect();
        outStream = btSocket.getOutputStream();
        inStream = btSocket.getInputStream();

        myLabel.setText("Bluetooth Connected");
        }

        void forwardButton() throws IOException {
        String msg = "f";
        msg += "\n";
        outStream.write(msg.getBytes());
        myLabel.setText("Data Sent");
        }

        void backwardButton() throws IOException {
        String msg = "b";
        msg += "\n";
        outStream.write(msg.getBytes());
        myLabel.setText("Data Sent");
        }

        void rightButton() throws IOException {
        String msg = "r";
        msg += "\n";
        outStream.write(msg.getBytes());
        myLabel.setText("Data Sent");
        }

        void leftButton() throws IOException {
        String msg = "l";
        msg += "\n";
        outStream.write(msg.getBytes());
        myLabel.setText("Data Sent");
        }

        void onButton() throws IOException {
        String msg = "o";
        msg += "\n";
        outStream.write(msg.getBytes());
        myLabel.setText("Data Sent");
        }

        void offButton() throws IOException {
        String msg = "q";
        msg += "\n";
        outStream.write(msg.getBytes());
        myLabel.setText("Data Sent");
        }

        void liftButton() throws IOException {
        String msg = "t";
        msg += "\n";
        outStream.write(msg.getBytes());
        myLabel.setText("Data Sent");
        }

        void lowButton() throws IOException {
        String msg = "w";
        msg += "\n";
        outStream.write(msg.getBytes());
        myLabel.setText("Data Sent");
        }

        void stopMotor() throws IOException {
        String msg = "s";
        msg += "\n";
        outStream.write(msg.getBytes());
        myLabel.setText("Data Sent");
        }

@Override
public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.my, menu);
        return true;
        }

        }
