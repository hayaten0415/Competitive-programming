use proconio::input;

fn main() {
  input! {
    a: u64,
    b: u64,
    c: u64,
  }
  let mut vec = vec![];
  vec.push(a);
  vec.push(b);
  vec.push(c);
  vec.sort();
  if vec[1] == b {
    println!("Yes");
  } else {
    println!("No");
  }
}
