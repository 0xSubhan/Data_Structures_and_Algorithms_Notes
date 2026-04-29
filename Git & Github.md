Git is a version conrtol system which track files for changes ! Like you have seen when we add new function in our project then git will track that new lines of code are added and track that change !

![[Screenshot from 2026-04-18 20-57-29.png]]

# git add

By doing `git add <filename>` , now that file will go into the stagging area !

## What `git add .` does

It stages **all changes in the current directory and subdirectories**:

- modified tracked files
- new files
- deleted files (depending on context/version/pathspec)

So if you run it casually, you may stage things you didn’t mean to commit.

## Why many people prefer `git add <specific-file>`

Because it gives you **control and intentional commits**.

### 1. Avoid committing accidental files

Example:

- debug.txt
- notes.md
- screenshot.png
- temporary script.py

`git add .` may include these if they’re in the repo and not ignored.

### 2. Cleaner commit history

Instead of one messy commit:

> fixed login + changed CSS + added notes + random test file

You can make focused commits:

- fix login validation
- improve navbar spacing
- update README

That makes history easier to understand and revert.

### 3. Safer in team projects

If you accidentally commit secrets, config changes, temp files, or unrelated code, teammates suffer too.

### 4. Helps you review changes consciously

When you choose files one by one, you naturally think:

> Do I really want this in the commit?

That habit is valuable.

# git commit 

git commit , a core Git function used to save a snapshot of your project's current changes to the local repository's history

## commit message best practice 

> Keep it atomic

![[Screenshot from 2026-04-18 21-33-06.png]]

![[Screenshot from 2026-04-19 15-41-01.png]]

# Git Branches

> Branches are like an alternative timeline.
> Every coder in the project can have their on timeline (branch) without effecting other's timeline!

![[Screenshot from 2026-04-19 22-28-47.png]]

As you can see in the diagram the green line represent the main branch timeline and that green nodes are checkpoints (commits) !

>We can create a new branch using `git branch <branch_name>` and switch to it using `git checkout <branch_name>`. When the new branch is first created, no files are changed, so both branches point to the same latest commit and share the same history. They remain identical until a new commit is made on either branch.

>When we create new branch then that creates new timeline and anything created inside that timeline is inaccessable to other branches until merged , so when we change the branch we can see that files that are being tracked inside the branch just disappear for other branches !
>

>Also about head , the head always point to the latest change in the branch !

![[Screenshot from 2026-04-22 15-02-11.png]]
See that the head is pointing to the latest change in that branch !

# Merging branches

In Git, a **merge** means combining changes from one branch into another. The two common outcomes are **fast-forward merge** and **not fast-forward merge**.

### fast forward merge

>This happens when the branch you're merging **has moved ahead in a straight line**, and the current branch(main) has no separate commits.

```
A---B---C   main
         \
          D---E   feature
```

You are on `main` and run:

```bash
git merge feature
```

Since `main` is still at `C` and has no new commits, Git simply moves `main` forward to `E`. (meaning moves the head pointer)

Result:

```
A---B---C---D---E   main, feature
```

No merge commit is created.

#### Why called fast-forward?

Because Git just **moves the pointer forward**.

### 2. Not Fast-Forward Merge

This happens when both branches have different commits, so Git cannot just move the pointer forward. It must create a **merge commit**.

```
A---B---C---F   main
         \
          D---E   feature
```

Now `main` got commit `F`, and `feature` has `D,E`.

Run:

```bash
git merge feature
```

Git combines both histories and creates merge commit `M`.

Result:

```css
A---B---C---F------M   main
         \        /
          D---E---    feature
          
```

#### Why needed?

Because history split into two paths, so Git must join them.

### Real Meaning

#### Fast Forward:

> "Nothing happened on main, so just move it to latest feature commit."

#### Not Fast Forward:

> "Both branches changed, so combine histories properly."

# Conflicts

### When do conflicts happen?

A conflict occurs when:

- Two branches edit the **same line(s)** in a file
- One branch deletes a file while the other modifies it
- Changes overlap in a way Git can’t safely auto-merge

### Simple example

Suppose you have this file in `main`:

```
color = "blue"color = "blue"
```

#### On `feature` branch:

```
color = "red"
```

#### On `main` branch:

```
color = "green"
```

Now when you try to merge:

```
git merge feature
```

Git sees:

- main says: `"green"`
- feature says: `"red"`

❌ It doesn’t know which one is correct → **conflict**

### What Git does when conflict happens

Git pauses the merge and marks the file like this:

```
<<<<<<< HEAD
color = "green"
=======
color = "red"
>>>>>>> feature
```

### 🧩 Meaning of markers

|Marker|Meaning|
|---|---|
|`<<<<<<< HEAD`|Your current branch (e.g., main)|
|`=======`|Separator|
|`>>>>>>> feature`|Incoming branch|
### How to resolve a conflict

You manually choose what the final code should be:

#### Option 1: Keep current branch

```
color = "green"
```

#### Option 2: Keep incoming branch

```
color = "red"
```

#### Option 3: Combine both (if meaningful)

```
color = "blue-red mix"
```

Then you remove the markers.

### After fixing

You must tell Git it's resolved:

```
git add file.txt
git commit
```


# Git diff & Git stash

## Git diff 

`git diff` is used to **see changes** between versions of files. It does **not** change anything—it only shows what is different.

Think of it as: **“What changed?”**

### 1. Compare working directory vs staged area

```
git diff
```

Shows changes you made in files **but have not staged** with `git add`.

Example:

```
-name = "Ali"
+name = "Ahmed"
```

- `-` old line
- `+` new line

### 2. Compare staged changes vs last commit

```
git diff --staged
```

Shows what is already added to staging and will go into the next commit.

### 3. Compare two commits

```
git diff commit1 commit2
```

```
git diff commit1..commit2
```

```
git diff 8c7964d..abdc3ff
```

### 4. Compare branches

```bash
git diff main feature
```

Shows what is different between two branches.

>When you run **`git diff` between branches**, the `-` and `+` symbols still mean the same thing—but now they represent differences between **two branches**, not just your local file edits.

```
git diff main feature
```

Means:

- **`-`** = line exists in **main** but not in **feature**
- **`+`** = line exists in **feature** but not in **main**

Git compares:

```bash
git diff <old_branch> <new_branch>
```

So first branch is treated as the “old/base” version, second as the “new/target” version.

```bash
git diff footer main
diff --git a/footer.html b/footer.html
index e6e2772..71d1720 100644
--- a/footer.html
+++ b/footer.html
@@ -1,4 +1,3 @@
 <footer>
-    Footer section created in footer branch!
-    footer2 icon pack!
+    Footer section created in footer branch testing it !
 </footer>
\ No newline at end of file
diff --git a/index.html b/index.html
index 89b074a..e95e886 100644
--- a/index.html
+++ b/index.html
@@ -1,2 +1,2 @@
 
-footer added successfully!
\ No newline at end of file
+footer added successfully!
```

The following means , the - lines exist in footer branch but does'nt exist in main branch and + lines exist in main branch but does'nt exist in footer branch !

### Why useful?

- Review your edits before commit
- Check what exactly changed
- Debug mistakes
- Compare branches/commits

## Git `stash`

`git stash` is used to **temporarily save your uncommitted work** and clean your working directory.

Think of it as: **“Hide my unfinished work for now.”**

Useful when you are coding something but suddenly need to switch branches or pull updates.

> Lets asume you are working on some branch and there is some work that needs to be done imediately in some other branch so we cant just leave the branch without commiting the changes because it will not let us leave if we dont commit our changes so thats were git stash come in handy !

### Example situation

You are editing files, but need to change branch:

```bash
git status
```

Shows modified files.

Run:

```bash
git stash
```

Git stores your changes and resets files back to last commit.

Now working directory becomes clean.

### Later restore changes

```bash
git stash pop
```

This brings back the saved changes and removes them from stash list.

### Keep stash but also restore

```bash
git stash apply
```

Restores changes **without deleting** the stash entry.

### View saved stashes

```bash
git stash list
```

Example:

```
stash@{0}: WIP on main
stash@{1}: WIP on feature
```

### Delete stash manually

```
git stash drop stash@{0}
```

Remove all:

```
git stash clear
```

## Real-world analogy

### `git diff`

Like comparing two drafts of a document and highlighting changes.

### `git stash`

Like putting unfinished work into a drawer so you can use the desk for something else.

>Git let you switch to `main` because your uncommitted changes could be carried over safely, but blocked switching to `footer` because that checkout would overwrite conflicting local changes.

## git checkout `<hash>`

>`git checkout <hash>` means **move your HEAD to a specific commit** using that commit’s SHA hash, so you can view the project exactly as it was at that moment.

A commit hash looks like:

```
a1b2c3d4
```

### What happens when you run it

```
git checkout a1b2c3d4
```

Git updates your files to match that commit.

Your branch pointers (`main`, `feature`) do **not** move. Instead, `HEAD` points directly to the commit.

This is called **detached HEAD state**.

### Normal state vs detached HEAD

#### Normal state

```
A---B---C   main (HEAD)
```

HEAD points to branch `main`, which points to commit `C`.

#### After checkout old commit `B`

```
A---B---C   main
    ^
   HEAD
```
Now HEAD points directly to commit `B`.

### Why use it?

- View old version of project
- Test older commit
- Recover files / inspect history

### Return to your branch

```
git checkout main
```

Or replace main with branch name !

---
# Git Rebase

## What is `git rebase`?

`git rebase` is a way to **move or replay commits from one branch onto another branch**.

Instead of creating a merge commit like `git merge`, rebase **takes your commits, removes them temporarily, updates your branch to the latest target branch, then reapplies your commits one by one on top of it**.

This creates a **clean, straight commit history**.

## Core Idea with Example

Suppose you have:

```bash
main:    A --- B --- C
               \
feature:        D --- E
```

- `main` got new commit `C`
    
- `feature` has commits `D`, `E`
    

Now run:

```bash
git checkout feature
git rebase main
```

Git does:

1. Saves commits `D`, `E`
    
2. Moves feature branch pointer to `C`
    
3. Replays `D`
    
4. Replays `E`
    

Now history becomes:

```bash
main:    A --- B --- C
                     \
feature:              D' --- E'
```

Notice:

- `D'` and `E'` are **new commits**, not same old ones.
    
- Hashes change.
    


# Why Use Rebase?

## 1. Cleaner History

Instead of merge commits:

```bash
main ---- C ---- M
         \      /
feature --D----E
```

You get:

```bash
main --- C --- D' --- E'
```

Much cleaner.

## 2. Easier to Read Timeline

Looks like work happened in sequence.

## 3. Update Feature Branch with Latest Main

Before merging PR.

# Rebase vs Merge

## Merge

```bash
git merge main
```

Creates merge commit.

## Rebase

```bash
git rebase main
```

Rewrites history and places commits on top.

# Common Real Workflow

Suppose you're working on `feature`.

Meanwhile `main` changed.

Use:

```bash
git checkout feature
git fetch origin
git rebase origin/main
```

Now your feature branch is updated with latest main cleanly.

# What Happens Internally?

Git finds:

## 1. Common Ancestor

The point where branches split.

## 2. Your Unique Commits

Commits after split.

## 3. Replays Them

One by one on top of target branch.

# Rebase Conflict (Very Important)

Conflicts happen when:

- Same file changed in both branches
    
- Same lines edited differently
    

## Example

`main`

```python
print("Hello World")
```

Your branch changed to:

```python
print("Hello Panther")
```

But `main` changed to:

```python
print("Hello User")
```

Now during rebase Git doesn't know which version to apply.

# Rebase Conflict Process

When you run:

```bash
git rebase main
```

Git stops and says conflict.

## Status Check

```bash
git status
```

Shows conflicted files.

## File Looks Like:

```python
<<<<<<< HEAD
print("Hello User")
=======
print("Hello Panther")
>>>>>>> feature commit
```


## Meaning

- `HEAD` = current target branch (`main`)
    
- Bottom = your rebased commit
    

# How to Resolve

Edit file manually:

```python
print("Hello Panther")
```

or combine:

```python
print("Hello User and Panther")
```

Then:

```bash
git add file.py
git rebase --continue
```

Git continues replaying next commits.

# If More Conflicts Come

Resolve again:

```bash
git add .
git rebase --continue
```

Until done.

# Cancel Rebase

If things go wrong:

```bash
git rebase --abort
```

Everything returns to previous state.

# Skip Current Commit

If one commit is useless:

```bash
git rebase --skip
```

Git ignores that commit.

# Important Rule

## Never Rebase Shared Public Branches

Bad:

```bash
main
develop
```

Because commit hashes change and confuse others.

Safe:

- Your personal feature branch
    
- Local unpublished branch
    

# Simple Mental Model

## Merge says:

> Combine both histories.

## Rebase says:

> Pretend my work started after latest main.

---
# Setup ssh for git & github

Setting up SSH for Git + GitHub lets you authenticate without typing your password every time. Here’s a clean step-by-step setup for Linux (works similarly on Mac too).

# ✅ 1. Check if you already have SSH keys

```bash
ls -al ~/.ssh
```

If you see files like:

- `id_ed25519`
    
- `id_rsa`
    

then you may already have a key.

# 🔑 2. Generate a new SSH key (recommended: ed25519)

Replace your email with your GitHub email:

```bash
ssh-keygen -t ed25519 -C "your_email@example.com"
```

If it says ed25519 not supported, use:

```bash
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```

### It will ask:

- **file location** → press Enter (default is fine)
    
- **passphrase** → optional but recommended
    

# 🚀 3. Start SSH agent

```bash
eval "$(ssh-agent -s)"
```

# ➕ 4. Add your SSH key to agent

```bash
ssh-add ~/.ssh/id_ed25519
```

(or `id_rsa` if you used RSA)

# 📋 5. Copy your SSH public key

```bash
cat ~/.ssh/id_ed25519.pub
```

Copy the full output (starts with `ssh-ed25519 ...`)

# 🌐 6. Add key to GitHub

Go to:

**GitHub → Settings → SSH and GPG keys → New SSH key**

- Title: anything (e.g. "My Laptop")
    
- Key: paste copied key
    
- Save
    

# 🧪 7. Test connection

```bash
ssh -T git@github.com
```

If successful, you’ll see:

```
Hi username! You've successfully authenticated...
```

# 🔗 8. Use SSH for your repo

When cloning:

```bash
git clone git@github.com:username/repo.git
```

If repo already exists locally, switch remote:

```bash
git remote set-url origin git@github.com:username/repo.git
```


---

# Github

These three commands are the standard steps to connect a local Git repository to GitHub (or any remote) and push your code for the first time.

## 1)

```bash
git remote add origin git@github.com:0xSubhan/new_test.git
```

### What it does:

This adds a **remote repository** to your local Git project.

### Breakdown:

- `git remote add` → tells Git you are adding a remote connection
    
- `origin` → just a **name/alias** for the remote (conventionally used for the main remote)
    
- `git@github.com:0xSubhan/new_test.git` → the **SSH URL** of your GitHub repo
    

### Meaning:

> “Hey Git, remember this GitHub repo as `origin` so I can push/pull later.”

## 2)

```bash
git branch -M main
```

### What it does:

This **renames your current branch to `main`**.

### Breakdown:

- `git branch` → branch operations
    
- `-M` → “force rename” (moves/renames even if `main` already exists locally)
    
- `main` → new branch name
    

### Why it’s used:

Git used to default to `master`, but now GitHub uses `main`, so this ensures consistency.

### Meaning:

> “Make sure my current branch is called `main`.”

## 3)

```bash
git push -u origin main
```

### What it does:

This **pushes your local `main` branch to GitHub** and sets tracking.

### Breakdown:

- `git push` → send commits to remote
    
- `origin` → remote name (from step 1)
    
- `main` → branch you are pushing
    
- `-u` (or `--set-upstream`) → links local branch with remote branch
    

### Meaning:

> “Upload my `main` branch to GitHub and remember this connection for future pushes/pulls.”

## What happens overall?

After running all 3:

1. Your local repo knows GitHub as `origin`
    
2. Your branch is named `main`
    
3. Your code is uploaded to GitHub
    
4. Future commands become simpler:
    
    ```bash
    git push
    git pull
    ```
    

## One-line summary:

You are basically:

> connecting GitHub → naming your branch → uploading your code for the first time

## If you DON’T use `-u`

You run:

`git push origin main`

### What happens:

- ✔ Your code is still pushed to GitHub
- ✔ Remote branch `origin/main` is created/updated
- ❌ BUT Git does NOT remember the connection

So next time:

### Without `-u`:

You must always write:

```
git push origin main  
git pull origin main
```

---
**GitHub clone** and **pull** are related, but they are used at different stages.

## 1. `git clone` — Copy a remote repository to your computer

You use `clone` when the project does **not exist locally yet**.

Example:

```bash
git clone git@github.com:username/project.git
```

What it does:

- Downloads the entire repository from GitHub to your PC
    
- Creates a new folder named after the repo
    
- Downloads all commits/history
    
- Sets the remote connection named `origin`
    
- Usually checks out the default branch (`main`)
    

So after cloning:

```bash
project/
```

exists on your computer.

### Think of clone as:

> “Make me a full local copy of this GitHub repo.”


## 2. `git pull` — Get latest changes from GitHub into existing local repo

You use `pull` when the repo **already exists on your computer**, and you want updates.

Example:

```bash
git pull
```

What it does:

- Contacts GitHub
    
- Downloads new commits from remote branch
    
- Merges them into your current local branch
    

Usually same as:

```bash
git fetch +
git merge
```

## Example Workflow

### First time:

```bash
git clone git@github.com:username/project.git
cd project
```

### Later, next day:

```bash
git pull
```

to get teammates' or your pushed changes.

## Real World Analogy

### Clone:

Photocopy the entire book for the first time.

### Pull:

Get only the newly added pages later.

## Important Difference

|Command|Use When|Creates Folder?|Downloads Full Repo?|
|---|---|---|---|
|`git clone`|First time|Yes|Yes|
|`git pull`|Existing repo|No|Only new changes|

![[Screenshot from 2026-04-23 20-16-06.png]]

---

