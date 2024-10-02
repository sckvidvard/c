package com.example.lab1_buttons;

        import android.annotation.SuppressLint;
        import android.app.Activity;
        import android.os.Bundle;
        import android.view.View;
        import android.widget.AdapterView;
        import android.widget.ArrayAdapter;
        import android.widget.Button;
        import android.widget.EditText;
        import android.widget.LinearLayout;
        import android.widget.ListView;
        import android.widget.TextView;

public class Third extends Activity {
    Button bb1, bb2, bb3, bb4;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.second_act); //связываем класс для второй активности с разметкой
        //для второй активности, находящейся в файле second_act.xml
        Button bb4 = (Button) findViewById(R.id.b4);
    }


    public void toRG(View view) {
        onBackPressed();
    }
}

