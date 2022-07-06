import java.io.BufferedReader;
import java.io.FileReader;

public class Teacher extends Person{
    private String ID;
    private String[] answers;
    public Teacher() throws Exception
    {
        BufferedReader fin = new BufferedReader(new FileReader("Test_1.csv"));
        String temp = fin.readLine();
        String[] value = temp.split(",");
        Name = value[0];
        Faculty = value[1];
        ID = value[2];
        temp = fin.readLine();
        value = temp.split(",");
        int No = Integer.parseInt(value[0]);
        answers = new String[No];
        for (int i = 0;i<No;i++)
        {
            temp = fin.readLine();
            value = temp.split(",");
            answers[i] = value[5];
        }
        fin.close();
    }
    public String getID(){return ID;}
    public String [] getAnswers()
    {
        return answers;
    }
}
