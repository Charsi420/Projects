import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.FileWriter;
import java.io.IOException;

class  Test extends JFrame
{
    int row;
    public Panel frame;
    Teacher teach;
    Student [] Students;
    JRadioButton[][] Options;
    ButtonGroup[] button;
    JTextField name,roll,sec,fac;
    JLabel[] question;
    JFrame result,login;
    JButton log;
    boolean first = false;
    public Test(String[] mcqq, String[][] opt, int row, String[] squestions, int srow) throws Exception{
        teach = new Teacher();
        Students = null;
        this.row = row;
        Students = new Student[2];
        String[] hardm = new String[]{"c", "c", "a", "b", "c", "c", "a", "d", "b", "d"};
        String[] hards = new String[]{"Tehran", "6", "16", "1024 X 1000", "Mars", "6", "January", "1947", "1857", "Mark Zuckerberg"};
        Students[0] = new Student("Abdul Wahib","FOIT","L1F20BSCS0030","C4",hardm,teach.getAnswers(),hards);
        hardm = new String[]{"a", "b", "d", "d", "d", "c", "d", "a", "a", "c"};
        hards = new String[]{"Tehran", "3", "16", "1000 X 1000", "Mars", "8", "None", "1947", "1850", "Mark Zuckerberg"};
        Students[1] = new Student("Ali Ahmed","FOIT","L1F20BSCS0029","C8",hardm,teach.getAnswers(),hards);
        id(mcqq,opt,squestions,srow);
    }
    private void Regrow()
    {
        Student[] temp =  new Student[Students.length+1];
        for (int i = 0;i < Students.length;i++)
        {
            temp[i] = Students[i];
        }
        Students = temp;
    }
    public void id(String[] mcqq, String[][] opt, String[] squestions, int srow)
    {
        if(!first) {
            login = new JFrame();
            login.setLayout(new GridLayout(5, 2));
            login.add(new JLabel("Name : "));
            name = new JTextField();
            login.add(name);
            login.add(new JLabel("Roll No : "));
            roll = new JTextField();
            login.add(roll);
            login.add(new JLabel("Section : "));
            sec = new JTextField();
            login.add(sec);
            login.add(new JLabel("Faculty : "));
            fac = new JTextField();
            login.add(fac);
            login.add(new JLabel(" "));
            log = new JButton("Register");
            login.add(log);
            login.setSize(400, 200);
            login.setLocation(900, 200);
            login.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        }
        else
        {
            name.setText(" ");
            roll.setText(" ");
            sec.setText(" ");
            fac.setText(" ");
            login.setVisible(true);
        }
        login.addWindowListener( new WindowAdapter()
        {
            public void windowClosed(WindowEvent e)
            {
                StoreResult();
                System.exit(1);
            }
        });
        login.setVisible(true);
        log.addActionListener(e ->  {
            if (first)
                    {
                        login.setVisible(false);
                       result.dispose();
                        setVisible(true);
                        return;
                    }
                    first = true;
                    login.setVisible(false);
                    JButton submit = new JButton("Submit");
                    JRadioButton temp2 = new JRadioButton("a");
                    Font rfont =new Font(temp2.getFont().getName(),temp2.getFont().getStyle(),12);
                    question = new JLabel[row];
                    for (int i = 0 ; i < row ; i++)
                    {
                        question[i] = new JLabel((i+1)+") "+mcqq[i]);
                        question[i].setFont(rfont);
                    }
                    frame = new Panel();
                    frame.setLayout(new GridLayout(row+row,3));
                    Options = new JRadioButton[row][4];
                    button = new ButtonGroup[row];
                    for (int i = 0;i<row;i++)
                    {
                        frame.add(question[i]);
                        frame.add(new JLabel(" "));
                        frame.add(new JLabel(" "));
                        frame.add(new JLabel(" "));
                        Options[i][0] = new JRadioButton(opt[i][0]);
                        Options[i][1] = new JRadioButton(opt[i][1]);
                        Options[i][2] = new JRadioButton(opt[i][2]);
                        Options[i][3] = new JRadioButton(opt[i][3]);
                        Options[i][0].setActionCommand("a");
                        Options[i][1].setActionCommand("b");
                        Options[i][2].setActionCommand("c");
                        Options[i][3].setActionCommand("d");
                        Options[i][0].setFont(rfont);
                        Options[i][1].setFont(rfont);
                        Options[i][2].setFont(rfont);
                        Options[i][3].setFont(rfont);
                        button[i] = new ButtonGroup();
                        button[i].add(Options[i][0]);
                        button[i].add(Options[i][1]);
                        button[i].add(Options[i][2]);
                        button[i].add(Options[i][3]);
                        button[i].setSelected(Options[i][0].getModel(),true);
                        frame.add(Options[i][0]);
                        frame.add(Options[i][1]);
                        frame.add(Options[i][2]);
                        frame.add(Options[i][3]);
                    }
                    frame.setSize(900,500);
                    ScrollPane scp = new ScrollPane(ScrollPane.SCROLLBARS_ALWAYS);
                    scp.setSize(500, 500);
                    scp.add(frame);
                    setSize(1800,1080);
                    setLocation(2, 2);
                    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                    setUndecorated(true);
                    Panel type2 = new Panel();
                    type2.setLayout(new GridLayout(srow+srow+1,1));
                    type2.setSize(900,500);
                    JTextField[] ans = new JTextField[srow];
                    JLabel[] sq = new JLabel[srow];
                    rfont =new Font(temp2.getFont().getName(),temp2.getFont().getStyle(),14);
                    for (int i = 0;i < srow;i++)
                    {
                        sq[i] = new JLabel(squestions[i]);
                        sq[i].setFont(rfont);
                        type2.add(sq[i]);
                        ans[i] = new JTextField();
                        ans[i].setToolTipText("Type Here");
                        type2.add(ans[i]);
                    }
                    type2.add(submit);
                    ScrollPane scp1 = new ScrollPane(ScrollPane.SCROLLBARS_ALWAYS);
                    scp1.setSize(900, 500);
                    scp1.add(type2);
                    JSplitPane splitPane = new JSplitPane();
                    splitPane.setSize(1800, 1080);
                    splitPane.setDividerSize(0);
                    splitPane.setDividerLocation(1000);
                    splitPane.setOrientation(JSplitPane.HORIZONTAL_SPLIT);
                    splitPane.setLeftComponent(scp);
                    splitPane.setRightComponent(scp1);
                    add(splitPane);
                    setExtendedState(JFrame.MAXIMIZED_BOTH);
                    setVisible(true);
                    submit.addActionListener(e1 -> {
                        String[] att = new String[row];
                        String[] att2 = new String[srow];
                        for (int i = 0;i<row;i++) {
                            att[i] = button[i].getSelection().getActionCommand();
                            button[i].setSelected(Options[i][0].getModel(),true);
                        }
                        for (int i = 0;i<srow;i++)
                        {
                            att2[i] = ans[i].getText();
                            ans[i].setText(" ");
                        }
                        if (Students == null)
                        {
                            Students = new Student[1];
                        }
                        else
                            Regrow();
                        Students[Students.length-1] = new Student(name.getText(),fac.getText(),roll.getText(),
                                sec.getText(),att, teach.getAnswers(),att2);
                        String[][] temp = new String[0][0];
                        String[] temp1 = new String[0];
                        setVisible(false);
                        result = new JFrame();
                        result.setLayout(new GridLayout(1,1));
                        JRadioButton temp5 = new JRadioButton("a");
                        Font rfont1 =new Font(temp5.getFont().getName(),temp5.getFont().getStyle(),18);
                        JLabel sc = new JLabel("Your Score in MCQs is : "+ Students[Students.length-1].getScore());
                        sc.setFont(rfont1);
                        result.add(sc);
                        result.setSize(300,100);
                        result.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                        result.setLocation(1300, 200);
                        result.setVisible(true);
                        id(temp1,temp,temp1,0);
                    });
                }
        );
    }
    private void StoreResult()
    {
        try {
            FileWriter fout = new FileWriter("Result Test_1.csv");
            fout.write("Teacher : " + "," + "," + "," + "\n");
            fout.write(teach.getName() + "," + teach.getFaculty() + "," + teach.getID() + "," + "\n");
            if (Students == null)
            {
                fout.write("No Students.");
            }
            else {
                fout.write("Students : " + "," + "," + "," + "\n");
                for (int i = 0; i < Students.length; i++) {
                    fout.write(Students[i].getName() + "," + Students[i].getFaculty() + "," + Students[i].getReg() + ","
                            + Students[i].getSection() + "\n");
                    fout.write(Students[i].getScore() + "," + "," + "," + "\n");
                    fout.write(Students[i].getAttempt());
                }
            }
            fout.close();
            fout = new FileWriter("Result Test_2.csv");
            fout.write("Teacher : " + "," + "," + "," + "\n");
            fout.write(teach.getName() + "," + teach.getFaculty() + "," + teach.getID() + "," + "\n");
            if (Students == null)
            {
                fout.write("No Students.");
            }
            else {
                fout.write("Students : " + "," + "," + "," + "\n");
                for (int i = 0; i < Students.length; i++) {
                    fout.write(Students[i].getName() + "," + Students[i].getFaculty() + "," + Students[i].getReg() + ","
                            + Students[i].getSection() + "\n");
                    fout.write(Students[i].getAttempt2());
                }
            }
            fout.close();
        } catch (IOException ignored) {
        }
    }
}