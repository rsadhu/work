public class test{

public  static void  main(String[] argv)
{

    myIo obj = new myIo();
    obj.display("hello world");
    myIo obj1 = new myIo(argv);
    obj.displayAll();
}

}
