import pandas as pd
import matplotlib.pyplot as plt
import tkinter as tk
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib
import matplotlib.font_manager as fm

# 한글 폰트 설정
matplotlib.rc('font', family='Malgun Gothic')  # Windows용
matplotlib.rcParams['axes.unicode_minus'] = False  # 음수 깨짐 방지

# CSV 로드
df = pd.read_csv("starforce_compare_rate_result_graph.csv")

# Tkinter 초기 설정
root = tk.Tk()
root.title("Starforce 확률 비교 (횟수별)")

# 그래프 설정
fig, ax = plt.subplots(figsize=(12, 6))
canvas = FigureCanvasTkAgg(fig, master=root)
canvas.get_tk_widget().pack()

# 공통 그래프 함수
def plot_data(columns, label_prefix, alpha=1.0, show_text=False):
    colors = ['green', 'orange', 'red']
    labels = ['Success', 'Fail', 'Destroy']

    for i in range(3):
        y = df[columns[i]]
        ax.plot(df["Level"], y, label=f"{label_prefix} {labels[i]}", 
                marker=['D', 'x', '.'][i], color=colors[i], alpha=alpha, markersize=4)

        if show_text:
            for j in range(len(df)):
                ax.text(df["Level"][j], y[j] + 2, f"{y[j]:.2f}", fontsize=6, color=colors[i], ha='center', fontweight='bold')

# 개별 시각화 함수
def show_graph_for(count):
    ax.clear()
    columns = [f"{count}_Success", f"{count}_Fail", f"{count}_Destroy"]
    plot_data(columns, f"{count}회", alpha=1.0, show_text=True)
    finalize_plot(f"{count}회 시뮬레이션 확률")

# 전체 시각화
def show_all():
    ax.clear()
    plot_data(["500_Success", "500_Fail", "500_Destroy"], "500회", alpha=0.3)
    plot_data(["1000_Success", "1000_Fail", "1000_Destroy"], "1000회", alpha=0.4)
    plot_data(["5000_Success", "5000_Fail", "5000_Destroy"], "5000회", alpha=0.6)
    plot_data(["10000_Success", "10000_Fail", "10000_Destroy"], "10000회", alpha=1.0)
    finalize_plot("시뮬레이션 횟수별 전체 비교")

# 그래프 마무리
def finalize_plot(title):
    ax.set_title(title)
    ax.set_xlabel("Starforce Level")
    ax.set_ylabel("Rate (%)")
    ax.set_ylim(0, 100)
    ax.set_xticks(df["Level"])
    ax.set_yticks(range(0, 101, 10))
    ax.grid(True, which='major', linestyle='-', linewidth=1)
    ax.legend()
    canvas.draw()

# 버튼 UI
button_frame = tk.Frame(root)
button_frame.pack(pady=10)

tk.Button(button_frame, text="500회 보기", command=lambda: show_graph_for(500), width=15).grid(row=0, column=0, padx=5)
tk.Button(button_frame, text="1000회 보기", command=lambda: show_graph_for(1000), width=15).grid(row=0, column=1, padx=5)
tk.Button(button_frame, text="5000회 보기", command=lambda: show_graph_for(5000), width=15).grid(row=0, column=2, padx=5)
tk.Button(button_frame, text="10000회 보기", command=lambda: show_graph_for(10000), width=15).grid(row=0, column=3, padx=5)
tk.Button(button_frame, text="전체 보기", command=show_all, width=15).grid(row=0, column=4, padx=5)

# 기본 상태
show_graph_for(10000)

# 실행
root.mainloop()
