import os

# -- Project information -----------------------------------------------------

project = "Homework: Session 8-9"
author = "Rodrigo Sagastegui"
copyright = "2024, rorosaga"

# -- General configuration ---------------------------------------------------

extensions = ['breathe']

breathe_default_project = project
templates_path = ['_templates']
exclude_patterns = []

# -- Options for HTML output -------------------------------------------------

html_theme = 'alabaster'  # You can choose another theme if preferred
html_static_path = ['_static']

# -- Breathe Configuration ---------------------------------------------------

breathe_projects = {
    "Homework: Session 8-9": os.path.join(os.path.dirname(__file__), "../../build/docs/doxygen/xml")
}
