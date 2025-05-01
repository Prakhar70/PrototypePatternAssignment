# Assignment: Efficient Email Duplication with Personalization

## Background

You are designing a system that sends personalized email messages to a large number of recipients. The system supports two types of emails:

- A **standard email** with subject and body
- A **premium email** which includes additional fields like CC and BCC

Each email is based on a common template file stored on disk. The template includes a placeholder `[[name]]` that must be replaced with the recipient's actual name.

## Requirements

1. Implement two classes:
   - One for standard emails
   - One for premium emails (which inherits from the standard email)

2. The body of the email must be loaded from a template file. This file I/O is expensive and should be performed only once for the base object.

3. You should generate multiple personalized copies of the base email using a copy mechanism. Do not reload the file for each recipient.

4. Each copy should personalize the `[[name]]` placeholder with the recipient’s name.

5. Demonstrate the system by:
   - Loading a template file
   - Creating at least 3 personalized copies of both email types
   - Printing the personalized emails

## Constraints

- Avoid repeated file I/O operations
- Reuse logic through inheritance where possible
- Avoid if-else chains when duplicating different email types
- Ensure the code is clean, extensible, and uses good object-oriented principles

## Bonus

- Use `std::unique_ptr` for managing ownership
- Use `std::transform` for copying logic

## Deliverables

- `main.cpp`: Contains the main logic and demonstration
- `email_template.txt`: The email body template containing `[[name]]`
- Any supporting header files if needed