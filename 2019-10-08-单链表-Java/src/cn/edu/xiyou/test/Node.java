package cn.edu.xiyou.test;

public class Node {
    Object data;
    Node next;

    public Node(Object data) {
        this.data = data;
    }

    @Override
    public String toString() {
        return "Node{" +
                "data=" + data +
                ", next=" + next +
                '}';
    }

    //在单链表的最后面插入节点
    public Node appendNode(Node node){
        //定义当前节点
        Node currentNode=this;
        while (true){
            //判断当前节点的next是否为空，若为空，则直接将所要插入的节点赋给next即可
            if (currentNode.next == null) {
                currentNode.next = node;
                break;
            }
            //next若不为空，需要将next的值赋给当前节点，为下次循环做准备，这样就能将所要插入的节点插在链表的尾部
            currentNode=currentNode.next;
        }
        //将Node返回的好处是：可以实现连续插入
        return this;
    }
    public boolean isLast(){
        //如果当前节点的next为空，则为终端节点
        return this.next==null;
    }
    //删除节点
    public boolean removeNode(){
        boolean flag=true;
        //利用 try 捕获空指针异常，在 catch 里返回false，表明删除失败
        try{
            Node newNext=this.next.next;
            this.next=newNext;
        }catch (Exception e){
            flag=false;
        }
        return flag;
    }
    public void show(){
        Node currentNode=this;
        System.out.println(currentNode);
        while (currentNode.next!=null){
            System.out.println(currentNode.next);
            currentNode=currentNode.next;
        }
    }
    public void insert(Node node){
        Node nextNode=this.next;
        this.next=node;
        node.next=nextNode;
    }
}
