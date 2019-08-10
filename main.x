
fn(a) {
    fn(b) {
        a
    }
} True = 

fn(a) {
    fn(b) {
        b
    }
} False = 



fn(a) {
    fn(b) {
        a b a!!
    }
} And = 

fn(a) {
    fn(b) {
        b a a!!
    }
} Or = 

fn(a) {
    True False a!
} Not = 


fn(c) {
    fn(a) {
        fn(b) {
            b a c!!
        }
    }
} If =


// Do it 10,000 times to benchmark
10000 n = 
while (n) {
    "b" "a" False True And!! If!!! println!
    1 n - n =
}



