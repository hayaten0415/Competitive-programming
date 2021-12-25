use proconio::input;
use std::collections::*;

fn main() {
    input! {
        mut l : usize,
        mut r: usize,
        mut s: String
    }
    l -= 1;
    r -= l;
    let mut head = s.split_off(l);
    print!("{}", s);
    let tail = head.split_off(r);
    let z = head.chars().rev().collect::<String>();
    print!("{}", z);
    println!("{}", tail);
}
