package com.example.lab1_buttons;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;

public class Second extends Activity {
    Button bb1, bb2, bb3, bb4;
    private ListView lw, lw1;
    TextView tw1, tw2, tw3;
    private ArrayAdapter<String> arad, arad1;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.second_act); //связываем класс для второй активности с разметкой
        //для второй активности, находящейся в файле second_act.xml
        bb1 = (Button)findViewById(R.id.b1);
        bb2 = (Button)findViewById(R.id.b2);
        Button bb4 = (Button) findViewById(R.id.b4);
        tw1 =(EditText)findViewById(R.id.t1);
        arad=new ArrayAdapter<String>(this, R.layout.le);
        arad1=new ArrayAdapter<String>(this, R.layout.le);
        lw=(ListView)findViewById(R.id.lw); //получаем ссылку на ListView
        lw.setAdapter(arad); //устанавливаем для списка адаптер
        lw1=(ListView)findViewById(R.id.lw1); //получаем ссылку на ListView
        lw1.setAdapter(arad1); //устанавливаем для списка адаптер
        String []ar1=getResources().getStringArray(R.array.ar1);
        String []ar2=getResources().getStringArray(R.array.ar2);
        arad.addAll(ar1);
        arad1.addAll(ar2);

    }
    public void toRed(View view){
        String n = tw1.getText().toString();
        arad.add(n);

    }
    public void toBlue(View view){
        String n = tw1.getText().toString();
        arad1.add(n);

    }

    public void toRG(View view) {
        onBackPressed();
    }
}

