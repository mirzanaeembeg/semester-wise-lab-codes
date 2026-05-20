package rectangledemo;

public class Rectangle {
    private float length;
    private float width;
    
    Rectangle(){   
    }
    Rectangle(float length,float width){
        this.length=length;
        this.width=width;
    }
    public float getLength(){
        return length;
    }
    public void setLength(float length){
        this.length=length;
    }
    public float getWidth(){
        return width;
    }
    public void setWidth(float width){
        this.width=width;
    }
    public double getArea(){
        return length*width;
    }
    public double getPerimeter(){
        return 2*(length+width);
    }
    public Rectangle newRectangle(){
        Rectangle newR = new Rectangle();
        newR.length=this.length-1;
        newR.width=this.width-1;
        return newR;
    }
    public String toString(){
        return "Rectangle[length= "+length+", width= "+width+"]";
    }
}
