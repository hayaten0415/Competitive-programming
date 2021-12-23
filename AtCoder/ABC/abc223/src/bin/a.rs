use proconio::input;

fn main() {
    input! {
        x: u32
    }
    if x % 100 == 0 && x != 0{
        println!("Yes");
    }else {
        println!("No");
    }
}
