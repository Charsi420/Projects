import java.io.*;
public class Test_1 {
   private int No_Of_Questions;
    private String[] Questions;
    private String[][] mcq;
    public Test_1()throws Exception
    {
        BufferedReader fin = new BufferedReader(new FileReader("Test_1.csv"));

        fin.readLine();
        String temp = fin.readLine();
        String[] value = temp.split(",");
        No_Of_Questions = Integer.parseInt(value[0]);
        Questions = new String[No_Of_Questions];
        mcq = new String[No_Of_Questions][4];
        for (int i = 0;i<No_Of_Questions;i++)
        {
            temp = fin.readLine();
            value = temp.split(",");
            Questions[i]=value[0];
            mcq[i][0] = value[1];
            mcq[i][1] = value[2];
            mcq[i][2] = value[3];
            mcq[i][3] = value[4];
        }
        fin.close();
    }
    public int getNo(){return No_Of_Questions;}
    public String[] getQuestions(){return Questions;}
    public String[][] getMcq(){return mcq;}
}
