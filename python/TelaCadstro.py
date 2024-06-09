import tkinter as tk
from tkinter import ttk

def cadastrar():
    nome = entry_nome.get()
    endereco = entry_endereco.get()
    numero = entry_numero.get()
    bairro = entry_bairro.get()
    cidade = entry_cidade.get()
    uf = entry_uf.get()

    if nome and endereco and numero and bairro and cidade and uf:
        tree.insert("", tk.END, values=(nome, endereco, numero, bairro, cidade, uf))
        limpar_campos()

def limpar_campos():
    entry_nome.delete(0, tk.END)
    entry_endereco.delete(0, tk.END)
    entry_numero.delete(0, tk.END)
    entry_bairro.delete(0, tk.END)
    entry_cidade.delete(0, tk.END)
    entry_uf.delete(0, tk.END)

def fechar():
    root.destroy()

root = tk.Tk()
root.title("Cadastro de Clientes")

# Labels and Entry Widgets
tk.Label(root, text="Nome").grid(row=0, column=0, padx=10, pady=5, sticky=tk.W)
entry_nome = tk.Entry(root)
entry_nome.grid(row=0, column=1, padx=10, pady=5)

tk.Label(root, text="Endereço").grid(row=1, column=0, padx=10, pady=5, sticky=tk.W)
entry_endereco = tk.Entry(root)
entry_endereco.grid(row=1, column=1, padx=10, pady=5)

tk.Label(root, text="Nº").grid(row=2, column=0, padx=10, pady=5, sticky=tk.W)
entry_numero = tk.Entry(root)
entry_numero.grid(row=2, column=1, padx=10, pady=5)

tk.Label(root, text="Bairro").grid(row=3, column=0, padx=10, pady=5, sticky=tk.W)
entry_bairro = tk.Entry(root)
entry_bairro.grid(row=3, column=1, padx=10, pady=5)

tk.Label(root, text="Cidade").grid(row=4, column=0, padx=10, pady=5, sticky=tk.W)
entry_cidade = tk.Entry(root)
entry_cidade.grid(row=4, column=1, padx=10, pady=5)

tk.Label(root, text="UF").grid(row=5, column=0, padx=10, pady=5, sticky=tk.W)
entry_uf = tk.Entry(root)
entry_uf.grid(row=5, column=1, padx=10, pady=5)

# Buttons
tk.Button(root, text="Cadastrar", command=cadastrar, bg='green', fg='white').grid(row=6, column=0, padx=10, pady=10)
tk.Button(root, text="Limpar", command=limpar_campos, bg='green', fg='white').grid(row=6, column=1, padx=10, pady=10)
tk.Button(root, text="Fechar", command=fechar, bg='green', fg='white').grid(row=6, column=2, padx=10, pady=10)

# Treeview to display the data
columns = ("Nome", "Endereço", "Nº", "Bairro", "Cidade", "UF")
tree = ttk.Treeview(root, columns=columns, show="headings")
for col in columns:
    tree.heading(col, text=col)
tree.grid(row=7, column=0, columnspan=3, padx=10, pady=10)

root.mainloop()

