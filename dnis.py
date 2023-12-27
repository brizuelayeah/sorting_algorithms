import regex as re # Librería para trabajar con expresiones regulares

first_form_pattern = r'\d{8}[A-Z]'       # Expresión regular que reconoce un DNI (8 dígitos finalizados por una letra mayúscula)
second_form_pattern = r'[XYZ]\d{7}[A-Z]' # Expresión regular que reconoce un NIE (carácter "X", "Y" ó "Z" seguidos por 7 dígitos 
                                         # y finalizados por una letra mayúscula)

# Función que extrae los IDs (DNIs ó NIEs) de un fichero de entrada y los escribe en un fichero de salida
# eliminando la última letra en caso de ser un DNI y la primera y última letra en caso de ser un NIE
def extract_strings(input_filename, output_filename):
    extracted_dnis = []
    extracted_nies = []
    with open(input_filename, 'r', encoding = 'utf-8') as file:
        text = file.read()
    
    first_form_matches = re.findall(first_form_pattern, text)
    extracted_dnis.extend(first_form_matches)

    second_form_matches = re.findall(second_form_pattern, text)
    extracted_nies.extend(second_form_matches)

    with open(output_filename, 'w', encoding='utf-8') as output_file:
        for dni in extracted_dnis:
            output_file.write(dni[:-1] + '\n')
        for nie in extracted_nies:
            output_file.write(nie[1:-1] + '\n')

# Definición de ficheros a utilizar
input_file_path = 'funcionarios_a_txt.txt'
output_file_path = 'dnis_a_txt.txt'

# Llamada a la función
extract_strings(input_file_path, output_file_path)