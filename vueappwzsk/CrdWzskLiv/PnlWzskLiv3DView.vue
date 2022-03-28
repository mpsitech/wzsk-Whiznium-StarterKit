<template>
	<v-card v-if=initdone class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="11">
					<div>{{tag.Cpt}}</div>
				</v-col>
				<v-col align="end">
					<v-btn-toggle v-model="contapp.ButClaimOn">
						<v-btn
							fab
							small
							light
							color="primary"
							v-on:click="handleButClick('ButClaimClick')"
							:value="1"
							:disabled="!statshr.ButClaimActive"
						>
							<v-icon color="white">{{contapp.ButClaimOn ? 'mdi-cog' : 'mdi-cog-off'}}</v-icon>
						</v-btn>
					</v-btn-toggle>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text>
			<div
				class="my-2"
				style="height:500px"
			>
				<!-- IP divTre - INSERT -->
			</div>

			<v-row class="my-2">
				<v-col>
					<v-btn
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButPlayClick')"
						:disabled="!statshr.ButPlayActive"
					>
						<v-icon color="white">mdi-play</v-icon>
					</v-btn>
					&#160;
					<v-btn
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButStopClick')"
						:disabled="!statshr.ButStopActive"
					>
						<v-icon color="white">mdi-stop</v-icon>
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-2"
			>
				{{tag.HdgAcq}}
			</h3>

			<v-slider
				class="my-2"
				v-model="contiac.SldAin"
				v-on:end='updateEng(["contiac"])'
				:label="tag.CptAin"
				:min="statshr.SldAinMin"
				:max="statshr.SldAinMax"
				:disabled="!statshr.SldAinActive"
			>
				<template v-slot:append>
					<v-text-field
						v-model="contiac.SldAin"
						v-on:change='updateEng(["contiac"])'
						class="mt-0 pt-0"
						hide-details
						single-line
						type="number"
						style="width: 80px"
					/>
				</template>
			</v-slider>

			<v-text-field
				class="my-2"
				readonly
				outlined
				v-model="continf.TxtAst"
				:label="tag.CptAst"
			/>

			<v-text-field
				v-if="statshr.TxtAoaAvail"
				class="my-2"
				readonly
				outlined
				v-model="continf.TxtAoa"
				:label="tag.CptAoa"
			/>

			<v-row class="my-2">
				<v-col>
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButAsrClick')"
						:disabled="!statshr.ButAsrActive"
					>
						{{tag.ButAsr}}
					</v-btn>
					&#160;
					<v-btn
						class="my-2"
						color="primary"
						v-on:click="handleButClick('ButAirClick')"
						:disabled="!statshr.ButAirActive"
					>
						{{tag.ButAir}}
					</v-btn>
				</v-col>
			</v-row>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskLiv3DView',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskLiv3DView.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskLiv3DViewDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskLiv3DView"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskLiv3DViewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskLiv3DViewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskLiv3DView) this.contiac = dpcheng.ContIacWzskLiv3DView;
				if (dpcheng.ContInfWzskLiv3DView) this.continf = dpcheng.ContInfWzskLiv3DView;
				if (dpcheng.StatAppWzskLiv3DView) this.statapp = dpcheng.StatAppWzskLiv3DView;
				if (dpcheng.StatShrWzskLiv3DView) this.statshr = dpcheng.StatShrWzskLiv3DView;
				if (dpcheng.TagWzskLiv3DView) {
					Wzsk.unescapeBlock(dpcheng.TagWzskLiv3DView);
					this.tag = dpcheng.TagWzskLiv3DView;
				}

				if (dpcheng.ContInfWzskLiv3DView) {
					if (!this.continf.ButClaimOn) this.contapp.ButClaimOn = 0;
					else this.contapp.ButClaimOn = 1;
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskLiv3DViewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/

			handleDpchEngLive: function(dpcheng) {
				/*
				<!-- IP handleDpchEngLive - BEGIN -->
				*/
				console.log("PnlWzskLiv3DView.handleDpchEngLive()" + dpcheng);
				/*
				<!-- IP handleDpchEngLive - END -->
				*/
			},
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskLiv3DViewLive") this.handleDpchEngLive(obj.dpcheng);
				else if (obj.srefIxWzskVDpch == "DpchEngWzskLiv3DViewData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contapp: {
				ButClaimOn: 0,
			},

			contiac: null,

			continf: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
