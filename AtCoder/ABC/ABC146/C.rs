use proconio::input;

fn main() {
    input! {
        a: u64,
        b: u64,
        x: u64,
    }
    let digit = |mid: u64| -> u64 {
        let mut cn = 0;
        let mut tmp = mid;
        while tmp > 0 {
            cn+= 1;
            tmp /= 10;
        }
        cn
    };
    let cond = |mid: u64| -> bool {
        let mut cost = a * mid;
        let num = digit(mid);
        cost += b * num;
        if cost <= x {
            return true
        }
        false
    };
    let mut right = 1000000001;
    let mut left = 0;
    while (right - left) > 1 {
        let mid = (right + left) / 2;
        if cond(mid) {
            left = mid;
        }else {
            right = mid;
        }
    }
    println!("{}", left)
}
