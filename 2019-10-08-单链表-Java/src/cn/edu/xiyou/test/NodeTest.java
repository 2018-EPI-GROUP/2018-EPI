package cn.edu.xiyou.test;

public class NodeTest {
    public static void main(String[] args) {
        Node node = new Node(1);
        Node node2 = new Node(2);
        Node node3 = new Node(3);
        Node node4 = new Node(4);
        node.appendNode(node2);
        node.appendNode(node3);
        node2.appendNode(node4);
        System.out.println(node.data);
        System.out.println(node.next.data);
        System.out.println(node.next.next.data);
        System.out.println(node.next.next.next.data);
        System.out.println(node.isLast());
        System.out.println(node4.isLast());
        node.show();
        //System.out.println(node2.removeNode());
        //node.show();
        node2.insert(new Node(5));
        node.show();
    }
}
