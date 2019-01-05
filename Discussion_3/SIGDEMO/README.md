This is a demo to show off signals. This should help with Homework 1 and signal handling.

# Files

`demo`: the executable that you will run.

`demo.c`: the C file that you will edit.

`Makefile`: the Makefile that makes compiling demo.c easy.

# Demo

### Step 1: Familiarize yourself with the code.

Open `demo.c` and look at the different parts.


**\#define statements**: This maps each of the signal values to their corresponding name.

**do_nothing**: This is a function that does nothing!

**print_hi**: This is a function that only prints the string "Hi!".

**main**: the function that is called when the executable is run.

### Step 2: Run the demo
Don't do anything with the code just yet.
Open a terminal window from this demo folder. Your path should look something like `~/<file path here>/SIGDEMO`.

Run the demo with `./demo`.

You should see the string "I love CS 162!" (one of the most popular strings to use in this class) printed out once per second. You also should not see any prompts to type in new commands.

### Step 3: Please Stop

**Q**: How do I stop this?

**A**: Signals!

Press `CTRL-C`. After this, you should see that demo will stop printing out lines.

**What happened?** In your terminal window, there are predefined signals that you can send with keyboard shortcuts. This one happens to be the same as a copy shortcut (if you are a non-mac user), but it has even more meaning in a terminal setting. `CTRL-C` sends a `SIGINT` signal, which is a Terminate signal. As its name suggests, this tells the process to stop running.

### Step 4: Ignore the `SIGINT` signal

Uncomment the line `signal (SIGINT, do_nothing);`

Run `make` in your terminal to recompile your changes and run `./demo` again.

Press `CTRL-C` again, but this time you should notice that it doesn't do anything.

**What did we do?** With the `signal` function, you are telling your program that now you want the signal handler for `SIGINT` to be the `do_nothing` function. Since do_nothing does nothing, our `CTRL-C` trick shouldn't work any more when we run ./demo again. Try it out!

### Step 5: Are we stuck?

There are other signals like `CTRL-\`. Let's use that to exit out of our program.

Notice that we have a different' exit message now. This is because `CTRL-\` is a different type of signal. You can look into all the different types of signals on the signals discussion worksheet.

### Step 6: Customized Handlers

**Q**: Can we only do nothing to handle a signal?

**A**: No! You can use any kind of function to handle a signal.

Uncomment the line `signal (SIGQUIT, print_hi);`

Recompile using `make` and run `./demo` again.

Press `CTRL-\` and you should notice the string "Hi!" is printed but our program does not exit. This is because the signal is now running our custom handler instead of the handler that kills our program.

Oh, I guess we're stuck now that both our keyboard kill signals don't kill our program any more. Do we have to restart our computer? Leave it running forever? No! We can send a signal through another terminal window.

### Step 7: Find your target.

Find what process you need to stop.

Open another terminal window and run `ps -A` which will list all running processes. Find our `demo` process and find its PID (Process ID).

### Step 8: Go in for the kill.

In that other terminal window, run `kill -9 <insert demo PID here>`.

**What happened?** With the `kill` command, we sent a signal value `9` to our program. This represents the  `SIGKILL` signal. Like the others, this will kill our program, but it doesn't have a keyboard mapping like the other two we just used.

### Step 9: Can we get really stuck?

Uncomment the two lines `signal (SIGTERM, SIG_IGN); signal (SIGKILL, SIG_IGN);`. This should ignore most of the primary kill signals we use. There are others, but lets just pretend they don't exist right now. Notice that we are now using `SIG_IGN` instead of `do_nothing`. This is effectively the same thing, which is saying that we want to ignore these signals (do nothing when handling them).

Recompile and run the program now. Try to kill it with **steps 7 and 8**. Notice that it still kills the program.

**Q**: But didn't we ignore all our signals? Doesn't that mean none of them will work now?

**A**: Not all signals are equal. Some have a higher priority than others. We can redefine the signal handler for most signals, but not all of them. `SIGKILL` (signal with a value of 9) is one of them.


### Step 10: Resetting our Signals

**Q**: What if we want to ignore signals only in one section of code? How do we reference the original handlers?

**A**: We use the `SIG_DFL` to set the handler for the signal to be its default.

Uncomment the line `signal (SIGINT, SIG_DFL);`.

Compile with `make` and run `./demo` again. Notice that `CTRL-C` should now kill the program as it originally did.

### Conclusion

In this demo we learned about signal handling. In the C code, we redirected signals to custom handlers or to be ignored. Some can be redirected to new handler, and they can also can be reset to their default value. This is a powerful tool when handling interrupts, and it helps to gain a better understanding of how we can interact with our computers and terminals.
