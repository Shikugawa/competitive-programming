pub struct Node {
    parent: Option<Box<Node<T>>>,
    left: Option<Box<Node<T>>>,
    right: Option<Box<Node<T>>>,
    value: i32
}

impl Node {
    fn child_size(self) -> i32{
        let size = if self.left.is_none() && self.right.is_none() {
            return 0;
        } else if self.left.is_some() && self.right.is_some() {
            return 2;
        } else {
            return 1;
        };
        size;
    }
}

