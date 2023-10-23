from flask import Flask, request, jsonify
import pandas as pd

app = Flask(__name__)

# Load the Excel file into a Pandas DataFrame
df = pd.read_excel('student_data.xlsx')

@app.route('/get_student_marks', methods=['GET'])
def get_student_marks():
    # Get the 'name' parameter from the query string
    student_name = request.args.get('name')

    if student_name is not None:
        # Filter the DataFrame for the specified student's data
        student_data = df[df['Name'] == student_name]

        if not student_data.empty:
            # Extract marks for English, Science, and Maths
            english_marks = student_data['English'].values[0]
            science_marks = student_data['Science'].values[0]
            maths_marks = student_data['Maths'].values[0]

            # Create a JSON response
            response = {
                'Name': student_name,
                'English': english_marks,
                'Science': science_marks,
                'Maths': maths_marks
            }

            return jsonify(response)
        else:
            return "Student not found.", 404
    else:
        return "Please provide a 'name' parameter.", 400

if __name__ == '__main__':
    app.run(debug=True)
