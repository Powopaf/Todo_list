use std::env;
use std::fs::OpenOptions;
use std::io::Error;
use std::io::Write;

fn add_task(task: &str, day: &str, month: &str, year: &str) -> Result<(), Error> {
    let file_name = "data";
    let file = OpenOptions::new().append(true).open(file_name);
    let line = task.to_owned() + " " + day + " " + month + " " + year + "\n";
    file?.write_all(line.as_bytes())?;
    println!("Add new task {0} that must be done before {1} {2} {3}",
             task, day, month, year);
    Ok(())
}

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() <= 1 {
        println!("Display Task");
        }
    else if args.len() == 6 && args[1].eq("add") {
        let _ = add_task(&args[2], &args[3], &args[4], &args[5]); 
    }
    else if args[1].eq("del") {
        println!("Delete task");
    }
    else {
        println!("Provide help");
    }
}
