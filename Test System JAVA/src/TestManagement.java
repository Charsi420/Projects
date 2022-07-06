import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.*;
import java.awt.Frame;
public class TestManagement {
    public static void main(String[] args) throws Exception {
        Test_1 test1 = new Test_1();
        Test_2 test2 = new Test_2();
        int row = test1.getNo();
        int srow = test2.getNo();
        String[][] options = test1.getMcq();
        String[] mcq_questions = test1.getQuestions();
        String[] squestions = test2.getQuestions();
        Test test = new Test(mcq_questions,options,row,squestions,srow);
    }
}

