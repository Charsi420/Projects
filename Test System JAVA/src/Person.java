public class Person {
    protected String Name;
    protected String Faculty;
    protected Person(String N,String F)
    {
        Name = N;
        Faculty = F;
    }
    protected Person()
    {
    }
    protected String getName(){return Name;}
    protected String getFaculty(){return Faculty;}
}
