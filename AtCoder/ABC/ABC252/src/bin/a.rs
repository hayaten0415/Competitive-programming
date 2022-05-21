use proconio::input;

fn main() {
  input! {
    s: u128,
  }
  println!("{}", to_alphabet(s-97));
}

fn to_alphabet(n: u128) -> String {
    if n > 25 {
        format!(
            "{}{}",
            to_alphabet((n - n % 26) / 26 - 1),
            ALPHABET[(n % 26) as usize]
        )
    } else {
        ALPHABET[(n % 26) as usize].to_string()
    }
}

const ALPHABET: [&str; 26] = [
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s",
    "t", "u", "v", "w", "x", "y", "z",
];
