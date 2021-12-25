use proconio::input;

fn main() {
    input! {
        x: u32,
        y: u32
    }
    if x > y{
        println!("{}", 0);
    }else{
        let ans = (y - x + 9) / 10;
        println!("{}", ans);
    }
}
