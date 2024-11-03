use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() <= 1 {
        println!("Display Task");
        }
    else if args[1].eq("add") {
        println!("Add task");
    }
    else if args[1].eq("del") {
        println!("Delete task");
    }
    else {
        println!("Provide help");
    }
}
