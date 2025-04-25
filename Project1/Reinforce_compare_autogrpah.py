import pandas as pd
import matplotlib.pyplot as plt
import tkinter as tk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib
import matplotlib.font_manager as fm
from matplotlib.ticker import MultipleLocator

# 한글 폰트 설정
matplotlib.rc('font', family='Malgun Gothic')  # Windows
matplotlib.rcParams['axes.unicode_minus'] = False

# CSV 파일 불러오기
df = pd.read_csv("starforce_compare_rate_result_autograph.csv")  # 파일명만 바꾸면 됩니다

# Tkinter 설정
root = tk.Tk()
root.title("자동 강화 시뮬레이터 확률 시각화")

fig, ax = plt.subplots(figsize=(12, 6))
canvas = FigureCanvasTkAgg(fig, master=root)
canvas.get_tk_widget().pack()

def plot_data(columns, label_prefix, alpha=1.0, show_text=False):
    colors = ['green', 'orange', 'red']
    labels = ['성공', '실패', '파괴']
    markers = ['o', 'x', 'D']

    for i in range(3):
        y = df[columns[i]]
        ax.plot(df["Level"], y, label=f"{label_prefix} {labels[i]}", 
                marker=markers[i], color=colors[i], alpha=alpha, markersize=4)

        if show_text:
            for j in range(len(df)):
                ax.text(df["Level"][j], y[j] + 2, f"{y[j]:.2f}", fontsize=6, color=colors[i], ha='center', fontweight='bold')

def show_graph_for(count):
    ax.clear()
    columns = [f"{count}_Success", f"{count}_Fail", f"{count}_Destroy"]
    plot_data(columns, f"{count}회", alpha=1.0, show_text=True)
    finalize_plot(f"{count}회 자동 강화 시뮬레이션 결과")

def show_all():
    ax.clear()
    plot_data(["500_Success", "500_Fail", "500_Destroy"], "500회", alpha=0.3)
    plot_data(["1000_Success", "1000_Fail", "1000_Destroy"], "1000회", alpha=0.5)
    plot_data(["5000_Success", "5000_Fail", "5000_Destroy"], "5000회", alpha=1.0)
    finalize_plot("자동 강화 시뮬레이션 전체 비교")

def finalize_plot(title):
    ax.set_title(title)
    ax.set_xlabel("스타포스 단계")
    ax.set_ylabel("확률 (%)")
    ax.set_ylim(0, 100)
    ax.set_xticks(df["Level"])
    ax.set_yticks(range(0, 101, 10))  # 주요 눈금
    ax.yaxis.set_minor_locator(MultipleLocator(5))  # 5단위 보조 눈금
    ax.grid(True, which='major', linestyle='-', linewidth=1)  # 주요선
    ax.grid(True, which='minor', linestyle=':', linewidth=0.5, color='gray')  # 보조선
    ax.legend()
    canvas.draw()

# 버튼
button_frame = tk.Frame(root)
button_frame.pack(pady=10)

tk.Button(button_frame, text="500회 보기", command=lambda: show_graph_for(500), width=15).grid(row=0, column=0, padx=5)
tk.Button(button_frame, text="1000회 보기", command=lambda: show_graph_for(1000), width=15).grid(row=0, column=1, padx=5)
tk.Button(button_frame, text="5000회 보기", command=lambda: show_graph_for(5000), width=15).grid(row=0, column=2, padx=5)
tk.Button(button_frame, text="전체 비교", command=show_all, width=15).grid(row=0, column=3, padx=5)

# 기본 화면
show_graph_for(5000)

root.mainloop()
