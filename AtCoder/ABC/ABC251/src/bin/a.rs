use proconio::input;

fn main() {
  input! {
    s: String,
  }
  let mut d: Vec<char> = s.chars().collect();
  let f = d.len();
  for i in 0..6 {
    print!("{}", d[i % f]);
  }
  println!("");
}
