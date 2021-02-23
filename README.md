# Autocorrect and spellcheck webapp
A web application that gives autocomplete suggestions or checks the spellings of an input word.<br><br>
We often find ourselves grasping at a word that's on the tip of our tongue but we just cant pin it down, or wanting to check the spelling of a word that we're not sure of. This application aims to solve this problem.
The features include:
<ol>
  <li>  Two modes of operation that can be toggled-
    <ul>
      <li>  A word suggestion mode- Where the user can type in a partially completed word and the app will suggest predictions.</li>
      <li>  A spell check mode- Where the user can enter a word and check if the spelling is correct, if it is not the app also suggests words that may contain the correct spelling of the word that the user was trying to type.</li>
    </ul>
  </li>
  <li> The app keeps a track of the the 5 most frequently misspelt words</li>
  <li> The word of the day (the most frequently incorrectly spelt word) can be seen from the spelling.php page</li>
</ol>
We used an Apache server to host our application.

# How to use
<ol>
  <li>  Clone the repository </li>
  <li>  Place the folder in your server's root directory </li>
  <li>  Open the file DSproject.php in your browser
    <ul>
      <li>  Use the toggle button at the top to switch between spellcheck and word suggestion mode </li>
      <li>  Type in the word and press alt+h and depending on the mode it will either tell you if your spelling is correct or will give you suggestions</li>
    </ul>
  </li>
  <li>  To check the word of the day you can open the page spelling.php </li>
</ol>

# Team
This project was a team effort by

| Name | GitHub Profile |
|:---:|:---:|
|  Arvind Srinivasan | [arvindsrinivasan](https://github.com/arvindsrinivasan) |
|  Aveek Saha | [aveek-saha](https://github.com/aveek-saha) |
