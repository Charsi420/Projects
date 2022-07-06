public class Student extends Person{
    private String Reg;
    private String Section;
    private int Score;
    private String[] Attempt;
    private String[] Attempt2;
    public Student(String N,String F,String R,String S,String[] Att,String[] ans,String[] Att2)
    {
        super(N,F);
        Reg = R;
        Section = S;
        Score = 0;
        Attempt = new String[Att.length];
        System.arraycopy(Att,0,Attempt,0,Att.length);
        for (int i = 0;i< Attempt.length;i++)
        {
            if (ans[i].equals(Attempt[i])) {
                Score++;
            }
        }
        Attempt2 = new String[Att2.length];
        System.arraycopy(Att2,0,Attempt2,0,Att2.length);
    }
    public String getSection(){return Section;}
    public String getReg(){return Reg;}
    public int getScore()
    {
        return Score;
    }
    public String getAttempt()
    {
        String temp = "";
        for (int i = 0;i< Attempt.length;i++)
        {
            temp += (i+1)+") "+","+Attempt[i]+","+","+"\n";
        }
        return temp;
    }
    public String getAttempt2()
    {
        String temp = "";
        for (int i = 0;i< Attempt2.length;i++)
        {
            temp += (i+1)+") "+","+Attempt2[i]+","+","+"\n";
        }
        return temp;
    }
}
