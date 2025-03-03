# Overview

### Committing Code

To maintain a clean and stable codebase, follow these best practices when committing code:

1. **Use Pull Requests**
    - Direct commits to the `main` branch are discouraged.
    - Always create a new branch for your changes and submit a pull request (PR) for review.
    - Ensure your PR has a clear title and description explaining the changes.

2. **Keep Commits Focused**
    - Each commit should address a single issue or feature.
    - Avoid bundling unrelated changes into a single commit.

3. **Write Clear Commit Messages**
    - Use a concise summary in the first line (max 50 characters).
    - Optionally, add a detailed explanation in the following lines.
    - Example:
      ```
      Fix login bug causing session timeout
      ```

4. **Rebase and Squash When Necessary**
    - Before merging, clean up your commit history by rebasing or squashing redundant commits.
    - Avoid unnecessary merge commits by keeping your branch up to date with `main`.

5. **Run Tests and Linters**
    - Ensure all tests pass before submitting a PR.
    - Run code formatters and linters to maintain code consistency.

6. **Get a Review Before Merging**
    - At least one team member should review and approve your PR.
    - Address all comments before merging.

7. **Delete Branches After Merging**
    - Once a PR is merged, delete the branch to keep the repository tidy.
