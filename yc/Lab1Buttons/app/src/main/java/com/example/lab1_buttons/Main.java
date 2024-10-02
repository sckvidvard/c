package com.example.lab1_buttons;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;

/*public class Main extends Activity
        implements View.OnClickListener{*/
public class Main   extends Activity
        implements AdapterView.OnItemClickListener{
    private SharedPreferences preferences;  //ссылка на объект-настройку
    Button bb1, bb2, bb3, bb4, mb2, mb1;
    TextView tw1, tw2, tw3;
    private LinearLayout linearLayout;
    //private Object LinearLayout;
    private ArrayAdapter<String> arad;  //ссылка на стандартный строковый адаптер –
    //объект класса ArrayAdapter<String>
    private ListView lw;  //ссылка на ListView
    private int Nst;
    private View curView=null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        preferences = getSharedPreferences(  //метод getSharedPreferences возвращает объект-настройку
                //с именем, которое содержится в первом параметре.
                getString(R.string.preferences),        //имя настройки здесь берется из строкового ресурса
                MODE_PRIVATE                                   //скрытый режим – только наше приложение может читать
        );

        setContentView(R.layout.main_act);
        bb1 = (Button)findViewById(R.id.b1);
        bb2 = (Button)findViewById(R.id.b2);
        /*bb3 = (Button)findViewById(R.id.b3);*/
        bb4 = (Button)findViewById(R.id.b4);
        tw1 =(EditText)findViewById(R.id.t1);
        tw2 = (EditText)findViewById(R.id.t2);
        tw3 = (TextView)findViewById(R.id.t3);
        arad=new ArrayAdapter<String>(this, R.layout.le);
        /*lw=(ListView)findViewById(R.id.lw); //получаем ссылку на ListView*/
/*        lw.setAdapter(arad); //устанавливаем для списка адаптер*/
        arad.add("first"); // через метод add адаптера добавляем в список первую строку
        arad.add("second");
        /*lw.setOnItemClickListener(this);*/
        /*linearLayout = (LinearLayout)findViewById(R.id.mLL);*/
        /*bAdd.setOnClickListener(this::onAdd);
        bCopy.setOnClickListener(this::onCopy);*/
        int Nst;
        /*bb2.setEnabled(false);
        bb3.setEnabled(false);*/

    }
    protected void onResume() { //обработчик события, которое помещает активность на передний план
        super.onResume();              //вызов обработчика базового класса
        String intElKey = getString(R.string.k1); //получаем из строкового ресурса ключ
        //все ключи – строкового типа
        int intEl = preferences.getInt(intElKey, 5);
        String intElKey2 = getString(R.string.k2); //получаем из строкового ресурса ключ
        //все ключи – строкового типа
        String intEl2 = preferences.getString(intElKey2, "5");
        String intElKey3 = getString(R.string.k3); //получаем из строкового ресурса ключ
        //все ключи – строкового типа
        String intEl3 = preferences.getString(intElKey3, "5");
    }
    protected void onPause() {  //обработчик события, которое убирает активность с переднего плана
        super.onPause();               //вызов обработчика базового класса
        String s= tw1.getText().toString();   //извлекаем сохраняемые значения из EditText-ов
        SharedPreferences.Editor editor = preferences.edit(); //с помощью метода edit объекта-активности
        //получаем объект-редактор editor
        editor.putInt(getString(R.string.k1), s); //с помощью редактора помещаем в настройку
        //элемент.  Первый параметр putInt – ключ           						                        //элемента, взятый из строкового ресурса,
        //второй параметр – значение элемента,
        //извлеченное из соответствующего EditText-а
        …     //аналогично помещаем в настройку остальные элементы.  Для строковых элементов
        //используем putString
        editor.commit();   //применяем изменения настройки
    }




    @SuppressLint("ResourceAsColor")
    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
        String s = arad.getItem(position);
        tw1.setText(s);
        Nst = position;
        bb2.setEnabled(true);
        bb3.setEnabled(true);

        // Если curView не равен null, сбрасываем его цвет
        if (curView != null) {
            curView.setBackgroundColor(getResources().getColor(android.R.color.transparent));  // Сбрасываем цвет предыдущего элемента
        }

        // Устанавливаем цвет для текущего выбранного элемента
        view.setBackgroundColor(getResources().getColor(R.color.yellow));

        // Обновляем curView, чтобы хранить ссылку на текущее выбранное View
        curView = view;
    }

    /*@Override*/
    public void toRed(View view){
        Intent intent = new Intent(this, Second.class); //создаем объект класса Intent, в качестве
        //второго параметра передаем ему указание
        //класс активности, которую требуется открыть
        startActivity(intent); //запускаем активность.  Методу startActivity передаем параметр – объект
        //класса Intent, в котором содержатся сведения о классе запускаемой
        //активности


    }
    public void toBlue(View view){
        Intent intent = new Intent(this, Third.class); //создаем объект класса Intent, в качестве
        //второго параметра передаем ему указание
        //класс активности, которую требуется открыть
        startActivity(intent); //запускаем активность.  Методу startActivity передаем параметр – объект
        //класса Intent, в котором содержатся сведения о классе запускаемой
        //активности

    }
    public void toBlack(View view) {
        String s = arad.getItem(Nst);
        arad.remove(s);  // Удаляем выбранный элемент из адаптера
        curView = null;  // Сбрасываем ссылку на текущий выбранный элемент

        // Проверяем, остались ли элементы в списке
        if (arad.getCount() == 0) {
            bb2.setEnabled(false);  // Отключаем кнопку Edit, если список пуст
            bb3.setEnabled(false);  // Отключаем кнопку Delete, если список пуст
        } else {
            bb2.setEnabled(false);  // Отключаем Edit после удаления (ждём новый выбор элемента)
            bb3.setEnabled(false);  // Отключаем Delete после удаления (ждём новый выбор элемента)
        }
    }

    public void toRG(View view){
        arad.clear();
        bb2.setEnabled(false);
        bb3.setEnabled(false);
    }






}
