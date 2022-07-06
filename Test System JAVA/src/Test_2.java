import java.io.BufferedReader;
import java.io.FileReader;

public class Test_2  {
    private int No_Of_Questions;
    private String[] Questions;
    public Test_2()throws Exception
    {
        BufferedReader fin = new BufferedReader(new FileReader("Test_2.csv"));
        String temp = fin.readLine();
        No_Of_Questions = Integer.parseInt(temp);
        Questions = new String[No_Of_Questions];
        for (int i = 0;i<No_Of_Questions;i++)
        {
            Questions[i] = fin.readLine();
        }
        fin.close();
    }
    public int getNo(){return No_Of_Questions;}
    public String[] getQuestions(){return Questions;}
}
