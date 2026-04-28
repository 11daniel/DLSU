import os
import time
import pyautogui
import subprocess

def take_screenshots(file_directory, screenshot_directory, file_range):
    """
    Opens files in a given range, ensures they are full screen, takes full-screen screenshots, and saves them.
    
    :param file_directory: Directory containing files to open
    :param screenshot_directory: Directory to save screenshots
    :param file_range: Tuple (start, end) to determine which files to open
    """
    
    # Ensure screenshot directory exists
    os.makedirs(screenshot_directory, exist_ok=True)
    
    # Get sorted list of files
    files = sorted(os.listdir(file_directory))
    
    for index in range(file_range[0], min(file_range[1], len(files))):
        file_path = os.path.join(file_directory, files[index])
        
        try:
            # Open the file
            process = subprocess.Popen([file_path], shell=True)
            time.sleep(5)  # Wait for the file to fully open
            
            # Ensure the window is active
            pyautogui.click()  # Click to focus the window
            time.sleep(1)
            
            # Make the window full screen
            pyautogui.hotkey('alt', 'space')
            time.sleep(1)
            pyautogui.press('x')  # Maximize the window
            time.sleep(2)
            
            # Capture the screenshot
            file_name, _ = os.path.splitext(files[index])
            screenshot_path = os.path.join(screenshot_directory, f"{file_name}.png")
            pyautogui.screenshot(screenshot_path)
            print(f"Screenshot saved: {screenshot_path}")
            
            # Close the opened file
            process.terminate()
            time.sleep(1)
            
        except Exception as e:
            print(f"Error processing {file_path}: {e}")

if __name__ == "__main__":
    file_directory = r"C:\Users\nicos\OneDrive\Documents\DLSU\Term 8\NSSECU3\FileAnalysis\Recovered"
    screenshot_directory = r"C:\Users\nicos\OneDrive\Documents\DLSU\Term 8\NSSECU3\FileAnalysis\Screenshots"
    file_range = (49, 220)  # Adjust the range as needed
    
    take_screenshots(file_directory, screenshot_directory, file_range)
